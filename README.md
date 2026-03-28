# Computer Vision

A comprehensive collection of Computer Vision notebooks and experiments, covering classical image processing, deep learning models, object detection, transformers, and vision-language models.

---

## 📁 Repository Structure

```
Computer_vision/
├── Notebooks (Jupyter)
│   ├── Image Processing & Transformations
│   ├── Image Classification
│   ├── Object Detection
│   ├── Vision Transformers
│   ├── Vision-Language Models
│   └── Miscellaneous
├── cpp_integration/      # High-performance C++ image processing via pybind11
└── Sample Images & Data
```

---

## 🗂️ Notebooks

### 🖼️ Image Processing & Transformations

| Notebook | Description |
|----------|-------------|
| [`start.ipynb`](start.ipynb) | Basic image transformations with OpenCV — translation, rotation, shearing using `cv2.warpAffine()` |
| [`patch.ipynb`](patch.ipynb) | Patch-based image classification using Swin Transformer on CIFAR-10 |
| [`image_segmen.ipynb`](image_segmen.ipynb) | Image segmentation using K-Means clustering on pixel values |
| [`rf_img.ipynb`](rf_img.ipynb) | Feature extraction using Histogram of Oriented Gradients (HOG) + Random Forest classification |

---

### 🔎 Image Classification

| Notebook | Description |
|----------|-------------|
| [`image_classification.ipynb`](image_classification.ipynb) | Traditional ML (SVM, Random Forest, KNN) on cat/dog images using scikit-learn |
| [`image_classification_cnn.ipynb`](image_classification_cnn.ipynb) | CNN with TensorFlow/Keras on CIFAR-10 (Conv2D, MaxPooling, Dense layers) |
| [`image_classification_using_tf.ipynb`](image_classification_using_tf.ipynb) | Transfer learning with TensorFlow pretrained models on CIFAR-10 |
| [`cnn_vision.ipynb`](cnn_vision.ipynb) | CNN from scratch using PyTorch — classifies synthetically generated geometric shapes |
| [`multilabel.ipynb`](multilabel.ipynb) | Multi-label image classification using MLkNN (scikit-multilearn) |
| [`auto_ml_deep.ipynb`](auto_ml_deep.ipynb) | Automated deep learning model search with AutoKeras |

---

### 🎯 Object Detection

| Notebook | Description |
|----------|-------------|
| [`obj_detection.ipynb`](obj_detection.ipynb) | Object detection with pretrained YOLOv8n (ultralytics) |
| [`YOLO.ipynb`](YOLO.ipynb) | YOLOv8 inference with GPU (CUDA) support checks |
| [`yolo26.ipynb`](yolo26.ipynb) | Environment and dependency verification for YOLO setup |
| [`fasterr_cnn_resnet.ipynb`](fasterr_cnn_resnet.ipynb) | Faster R-CNN with ResNet-50 backbone (torchvision) for custom object detection |
| [`sssd.ipynb`](sssd.ipynb) | Single Shot MultiBox Detector (SSD) with VGG16 backbone |

---

### 🤖 Vision Transformers

| Notebook | Description |
|----------|-------------|
| [`vit.ipynb`](vit.ipynb) | Vision Transformer (ViT) training on CIFAR-10 using the `timm` library |
| [`CvT.ipynb`](CvT.ipynb) | Convolutional Vision Transformer (CvT) — combines convolutions with transformer blocks |
| [`attemtion.ipynb`](attemtion.ipynb) | Scaled dot-product attention mechanism implemented from scratch |

---

### 🌐 Vision-Language Models (VLM)

| Notebook | Description |
|----------|-------------|
| [`ALIGN.ipynb`](ALIGN.ipynb) | Image-text alignment with the ALIGN model (Hugging Face) — cosine similarity between image and text embeddings |
| [`BLIP.ipynb`](BLIP.ipynb) | Image captioning with Salesforce BLIP — generates natural language descriptions from images |
| [`VLM.ipynb`](VLM.ipynb) | Large multimodal model (Qwen2-VL-7B-Instruct) for vision-language tasks |

---

## ⚙️ C++ Integration

High-performance image processing module built with [pybind11](https://github.com/pybind/pybind11), callable directly from Python.

| File | Description |
|------|-------------|
| [`cpp_integration/cv_module.cpp`](cpp_integration/cv_module.cpp) | C++ implementations: Gaussian blur (3×3), image thresholding (`ImageProcessor` class), and basic pybind11 bindings |
| [`cpp_integration/setup.py`](cpp_integration/setup.py) | Build script to compile `cv_module.cpp` into the `cv_cpp_module` Python extension |
| [`cpp_integration/mylib.cpp`](cpp_integration/mylib.cpp) | Additional C++ utility library |

**Build the C++ module:**
```bash
cd cpp_integration
python setup.py build_ext --inplace
```

---

## 🚀 Getting Started

### Prerequisites

```bash
pip install numpy opencv-python torch torchvision tensorflow keras
pip install ultralytics timm transformers scikit-learn scikit-multilearn
pip install autokeras pybind11
```

### Run a Notebook

```bash
jupyter notebook
```

Then open any notebook from the file browser.

---

## 🛠️ Technologies Used

- **Deep Learning:** PyTorch, TensorFlow/Keras, timm, Hugging Face Transformers
- **Classical ML:** scikit-learn, scikit-multilearn
- **Computer Vision:** OpenCV, ultralytics (YOLOv8)
- **AutoML:** AutoKeras
- **Vision-Language:** ALIGN, BLIP, Qwen2-VL
- **C++ Integration:** pybind11
- **Visualization:** Matplotlib

---

## 📊 Datasets Used

- **CIFAR-10** — 10-class image classification benchmark
- **Cats vs Dogs** — Binary classification dataset
- **COCO** — Common Objects in Context (used via YOLO pretrained weights)
- Custom synthetic images (geometric shapes)

---

## 📝 License

This project is for educational and research purposes.
