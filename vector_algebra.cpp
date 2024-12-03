#include <cmath>
#include <pybind11/pybind11.h>

namespace py = pybind11;

class Vector3D {
public:
    float x, y, z;

    Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3D normalize() const {
        float len = length();
        return Vector3D(x / len, y / len, z / len);
    }
};

// Функции для работы с векторами
Vector3D add(const Vector3D& v1, const Vector3D& v2) {
    return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector3D subtract(const Vector3D& v1, const Vector3D& v2) {
    return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

float dot(const Vector3D& v1, const Vector3D& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Экспортируем функции и класс в Python
PYBIND11_MODULE(vector_algebra, m) {
    py::class_<Vector3D>(m, "Vector3D")
        .def(py::init<float, float, float>())
        .def("length", &Vector3D::length)
        .def("normalize", &Vector3D::normalize)
        .def_readonly("x", &Vector3D::x)
        .def_readonly("y", &Vector3D::y)
        .def_readonly("z", &Vector3D::z);

    m.def("add", &add, "Add two vectors");
    m.def("subtract", &subtract, "Subtract two vectors");
    m.def("dot", &dot, "Dot product of two vectors");
}
