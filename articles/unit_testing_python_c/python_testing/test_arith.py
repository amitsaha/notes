import unittest
import myarith

class ArithTest(unittest.TestCase):
    
    def test_sum(self):
        self.assertEqual(myarith.sum(1,2), 1+2)
