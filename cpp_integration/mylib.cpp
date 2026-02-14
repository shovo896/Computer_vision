// Simple C++ library for Python integration using ctypes
#include <iostream>

extern "C" {
    // Simple addition function
    int add(int a, int b) {
        return a + b;
    }
    
    // Image processing: Convert RGB to Grayscale
    void rgb_to_gray(unsigned char* rgb, unsigned char* gray, int width, int height) {
        for (int i = 0; i < width * height; i++) {
            int r = rgb[i * 3];
            int g = rgb[i * 3 + 1];
            int b = rgb[i * 3 + 2];
            // Luminance formula
            gray[i] = static_cast<unsigned char>(0.299 * r + 0.587 * g + 0.114 * b);
        }
    }
    
    // Fast array sum (performance comparison with Python)
    double array_sum(double* arr, int size) {
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }
}
