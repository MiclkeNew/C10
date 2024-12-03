from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        'vector_algebra',
        ['vector_algebra.cpp'],
        include_dirs=[pybind11.get_include()],
        language='c++'
    ),
]

setup(
    name='vector_algebra',
    ext_modules=ext_modules,
    zip_safe=False,
)
