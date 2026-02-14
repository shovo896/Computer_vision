from setuptools import setup, Extension
import pybind11

# Define the extension module
ext_modules = [
    Extension(
        'cv_cpp_module',
        ['cv_module.cpp'],
        include_dirs=[pybind11.get_include()],
        language='c++',
        extra_compile_args=['-std=c++11'],
    ),
]

setup(
    name='cv_cpp_module',
    version='0.1',
    author='Your Name',
    description='C++ Computer Vision module for Python',
    ext_modules=ext_modules,
    zip_safe=False,
)
