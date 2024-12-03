import unittest
from vector_algebra import Vector3D, add, subtract, dot

class TestVectorAlgebra(unittest.TestCase):

    def test_add(self):
        v1 = Vector3D(1, 2, 3)
        v2 = Vector3D(4, 5, 6)
        result = add(v1, v2)
        self.assertEqual(result.x, 5)
        self.assertEqual(result.y, 7)
        self.assertEqual(result.z, 9)

    def test_subtract(self):
        v1 = Vector3D(4, 5, 6)
        v2 = Vector3D(1, 2, 3)
        result = subtract(v1, v2)
        self.assertEqual(result.x, 3)
        self.assertEqual(result.y, 3)
        self.assertEqual(result.z, 3)

    def test_dot(self):
        v1 = Vector3D(1, 0, 0)
        v2 = Vector3D(0, 1, 0)
        result = dot(v1, v2)
        self.assertEqual(result, 0)

    def test_length(self):
        v = Vector3D(3, 4, 0)
        self.assertEqual(v.length(), 5)

    def test_normalize(self):
        v = Vector3D(0, 0, 5)
        norm = v.normalize()
        self.assertEqual(norm.length(), 1)

if __name__ == '__main__':
    unittest.main()
