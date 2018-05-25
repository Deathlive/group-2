import numpy as np

class Polynomial(object):
    def __init__(self, coeffs):
        self.coeffs = coeffs

    def str_power(self, d, X='X'):
        if d == 0:
            return ''
        if d == 1:
            return X
        return X+'^{}'.format(d)

    def __str__(self):
        s = "Polynomial: "
        lens = len(self.coeffs)-1
        for i in range(len(self.coeffs)):
            s += str(self.coeffs[i]) + self.str_power(lens)
            if i != len(self.coeffs)-1:
                s += " + "
            lens -= 1
        return s

    def __add__(self, other):
        maxLength = max(len(self.coeffs), len(other.coeffs))
        return Polynomial([self[index] + other[index] for index in range(maxLength)])

    def __sub__(self, other):
        maxLength = max(len(self.coeffs), len(other.coeffs))
        return Polynomial([self[index] - other[index] for index in range(maxLength)])

    def __getitem__(self, index):
        try:
            return self.coeffs[index]
        except IndexError:
            return 0.

    def __mul__(self, other):
        leng = len(self.coeffs) + len(other.coeffs)
        length = leng - 1
        newCoeffs = [sum(self[j]*other[i-j] for j in range(i+1)) for i in range(length)]
        return Polynomial(newCoeffs)

    def value(self, x):
        def simpleMult(a, b): 
            return a * x + b

        def reduces(function, iterable):
            it = iter(iterable)
            value = 0
            for element in it:
                value = function(value, element)
            return value

        return reduces(simpleMult, self.coeffs)

    def root(self):
        if len(self.coeffs) == 3:
            d = self.coeffs[1] ** 2 - 4 * self.coeffs[0] * self.coeffs[2]
            if d == 0:
                return -self.coeffs[1] / 2 * self.coeffs[0]
            elif d < 0:
                return None
            else:
                x1 = (-self.coeffs[1] + d ** 0.5) / 2 * self.coeffs[0]
                x2 = (-self.coeffs[1] - d ** 0.5) / 2 * self.coeffs[0]
                res = [x1, x2]
                return res
        else:
            r = np.roots(self.coeffs)
            return r[np.isreal(r)]

def main():
    p1 = Polynomial([2, 2, 1])
    p2 = Polynomial([6, 1, -5])
    p3 = Polynomial([3, 4, 2, 2])

    print("___Print Polynomial___")
    print(p1)
    print(p2)
    print(p3)

    print()

    print("___Print Arithmetic Operations___")
    print(p1 * p2)
    print(p1 + p2)
    print(p1 - p2)
    print(p1 - p3)

    print()


    print("___Print Root___")
    print("p1 Root: ", p1.root())
    print("p2 Root: ", p2.root())
    print("p3 Root: ", p3.root())

    print()

    x = 2
    print("___Print Result: X = %d___" % (x))
    print("p1 Value: ", p1.value(x))
    print("p2 Value: ", p2.value(x))
    print("p3 Value: ", p3.value(x))

main()