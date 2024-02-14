from service import services
import unittest
import random
from matrices import computer
from matrices import user

class test_service (unittest.TestCase):
    def test_matrix_find (self):
        matrx=[[1, 2, 3],[3, 4, 5]]
        Service=services(matrx)
        self.assertEqual(Service.matrix_find(0, 0), "HEAD")
        self.assertEqual(Service.matrix_find(0, 1), "WING")
        self.assertEqual(Service.matrix_find(0, 2), "BODY")   

    def test_full_body(self):
        m=[[0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 2, 2, 3, 2, 2, 0, 0, 0],
            [0, 0, 0, 0, 3, 0, 0, 0, 0, 0],
            [0, 2, 0, 2, 3, 2, 0, 0, 0, 0],
            [0, 2, 0, 2, 0, 0, 0, 0, 0, 0],
            [1, 3, 3, 3, 0, 0, 0, 0, 0, 0],
            [0, 2, 0, 2, 0, 0, 1, 0, 0, 0],
            [0, 2, 0, 0, 2, 2, 3, 2, 2, 0],
            [0, 0, 0, 0, 0, 0, 3, 0, 0, 0],
            [0, 0, 0, 0, 0, 2, 3, 2, 0, 0]]

        Service=services(m)
        self.assertIsNotNone(Service.full_body(1,4) )

    def test_they_hit_me(self):
        m=[[0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 2, 2, 3, 2, 2, 0, 0, 0],
            [0, 0, 0, 0, 3, 0, 0, 0, 0, 0],
            [0, 2, 0, 2, 3, 2, 0, 0, 0, 0],
            [0, 2, 0, 2, 0, 0, 0, 0, 0, 0],
            [1, 3, 3, 3, 0, 0, 0, 0, 0, 0],
            [0, 2, 0, 2, 0, 0, 1, 0, 0, 0],
            [0, 2, 0, 0, 2, 2, 3, 2, 2, 0],
            [0, 0, 0, 0, 0, 0, 3, 0, 0, 0],
            [0, 0, 0, 0, 0, 2, 3, 2, 0, 0]]
        Service=services(m)
        self.assertEqual(Service.they_hit_me(0, 4), "head hit")
        self.assertEqual(Service.they_hit_me(1, 4), "body hit")
        self.assertEqual(Service.they_hit_me(1, 5), "wing down")
        self.assertIsNone(Service.they_hit_me(0, 0))

    def test_wing_hit(self):
        m=[[0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 2, 2, 3, 2, 2, 0, 0, 0],
            [0, 0, 0, 0, 3, 0, 0, 0, 0, 0],
            [0, 2, 0, 2, 3, 2, 0, 0, 0, 0],
            [0, 2, 0, 2, 0, 0, 0, 0, 0, 0],
            [1, 3, 3, 3, 0, 0, 0, 0, 0, 0],
            [0, 2, 0, 2, 0, 0, 1, 0, 0, 0],
            [0, 2, 0, 0, 2, 2, 3, 2, 2, 0],
            [0, 0, 0, 0, 0, 0, 3, 0, 0, 0],
            [0, 0, 0, 0, 0, 2, 3, 2, 0, 0]]
        Service=services(m)
        Service.attack
        Service.wing_hit
        #self.assertEqual(first, second)
    
    def test_comp(self):
         m = [[0 for col in range(10)]  for row in range(10)]
         self.assertNotEqual(computer.compm(), m)
    
    def test_user(self):
        m = [[0 for col in range(10)]  for row in range(10)]
        self.assertEqual(user.userm(), m)

unittest.main()