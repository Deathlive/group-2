# 2
import unittest

def add(a, b):
    '''The addition of a and b'''
    return a + b

class AddTest(unittest.TestCase):
    '''
        Check for correct answer
    '''
    def test_add_int(self):
        result = add(2, 5)
        self.assertEqual(result, 7)

    def test_add_floats(self):
        result = add(5.5, 2)
        self.assertEqual(result, 7.5)

    def test_add_strings(self):
        result = add('abc', 'def')
        self.assertEqual(result, 'abcdef')

if __name__ == '__main__':
    unittest.main()