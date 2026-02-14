// C++ code with pybind11 for better Python integration
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <vector>

namespace py = pybind11;

// Simple function
int multiply(int a, int b) {
    return a * b;
}

// Fast image processing with NumPy arrays
py::array_t<uint8_t> gaussian_blur_cpp(py::array_t<uint8_t> input) {
    auto buf = input.request();
    
    if (buf.ndim != 2) {
        throw std::runtime_error("Input should be 2D array");
    }
    
    auto result = py::array_t<uint8_t>(buf.size);
    auto buf_out = result.request();
    
    uint8_t *ptr_in = static_cast<uint8_t *>(buf.ptr);
    uint8_t *ptr_out = static_cast<uint8_t *>(buf_out.ptr);
    
    // Simple 3x3 Gaussian kernel
    int height = buf.shape[0];
    int width = buf.shape[1];
    
    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int sum = 0;
            // 3x3 kernel
            sum += ptr_in[(y-1) * width + (x-1)] * 1;
            sum += ptr_in[(y-1) * width + x] * 2;
            sum += ptr_in[(y-1) * width + (x+1)] * 1;
            sum += ptr_in[y * width + (x-1)] * 2;
            sum += ptr_in[y * width + x] * 4;
            sum += ptr_in[y * width + (x+1)] * 2;
            sum += ptr_in[(y+1) * width + (x-1)] * 1;
            sum += ptr_in[(y+1) * width + x] * 2;
            sum += ptr_in[(y+1) * width + (x+1)] * 1;
            
            ptr_out[y * width + x] = sum / 16;
        }
    }
    
    result.resize({height, width});
    return result;
}

// Class example
class ImageProcessor {
public:
    ImageProcessor(int threshold) : threshold_(threshold) {}
    
    py::array_t<uint8_t> threshold_image(py::array_t<uint8_t> input) {
        auto buf = input.request();
        auto result = py::array_t<uint8_t>(buf.size);
        auto buf_out = result.request();
        
        uint8_t *ptr_in = static_cast<uint8_t *>(buf.ptr);
        uint8_t *ptr_out = static_cast<uint8_t *>(buf_out.ptr);
        
        for (size_t i = 0; i < buf.size; i++) {
            ptr_out[i] = ptr_in[i] > threshold_ ? 255 : 0;
        }
        
        result.resize(buf.shape);
        return result;
    }
    
    void set_threshold(int t) { threshold_ = t; }
    int get_threshold() const { return threshold_; }
    
private:
    int threshold_;
};

// Pybind11 module definition
PYBIND11_MODULE(cv_cpp_module, m) {
    m.doc() = "C++ Computer Vision functions with pybind11";
    
    m.def("multiply", &multiply, "Multiply two numbers",
          py::arg("a"), py::arg("b"));
    
    m.def("gaussian_blur_cpp", &gaussian_blur_cpp, 
          "Fast Gaussian blur using C++",
          py::arg("input"));
    
    py::class_<ImageProcessor>(m, "ImageProcessor")
        .def(py::init<int>(), py::arg("threshold"))
        .def("threshold_image", &ImageProcessor::threshold_image)
        .def("set_threshold", &ImageProcessor::set_threshold)
        .def("get_threshold", &ImageProcessor::get_threshold)
        .def_property("threshold", 
                     &ImageProcessor::get_threshold, 
                     &ImageProcessor::set_threshold);
}
