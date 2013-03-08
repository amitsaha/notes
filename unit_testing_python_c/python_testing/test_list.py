"""
Tests for a Python list
"""
import unittest

class TestLists(unittest.TestCase):
    
    def setUp(self):
        self.alist = list(range(10))

    def test_type(self):
        self.assertEqual(type(self.alist), type(list()))

    def test_append(self):
        self.assertTrue(999 not in self.alist)
        self.alist.append(999)
        self.assertTrue(999 in self.alist)

if __name__=='__main__':
    unittest.main()

