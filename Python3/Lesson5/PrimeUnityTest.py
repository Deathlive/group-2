# 1
import unittest

def isPrime(n):
    '''Check if integer n is a prime'''
    if n < 0:
        return False
    if n < 2:
        return False
    if n == 2: 
        return True    
    if not n & 1: 
        return False
    for x in range(3, n):
        if n % x == 0:
            return False
    return True

class PrimeUnityTest(unittest.TestCase):
    '''
        Check Five is prime
        Check is Four is not prime
        Check if 0 is not prime
        Ensure all negative numbers are not prime 
    '''
    def test_is_five_prime(self):
        self.assertTrue(isPrime(5))

    def test_four_is_not_prime(self):
        self.assertFalse(isPrime(4), 'Four is not prime')

    def test_zero_is_not_prime(self):
        self.assertFalse(isPrime(0), "Zero is not prime")
 
    def test_negative_number(self):
        for index in range (-1, -10, -1):
            self.assertFalse(isPrime(index))

if __name__ == '__main__':
    unittest.main()