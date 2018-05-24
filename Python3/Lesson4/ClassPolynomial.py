class Polynomial(object):
    def __init__(self, coeffs):
        self.coeffs = coeffs

    def __str__(self):
        s = ""
        s += "Polynomial: " + str(self.coeffs[0]) + "x^2" 
        if self.coeffs[1] > 0:
            s += " + "
        else:
            s += " "
        s += str(self.coeffs[1]) + "x"

        if self.coeffs[2] > 0:
            s += " + "
        else:
            s += " "
        s += str(self.coeffs[2])

        return s

    def __add__(self, other):
        a1 = self.coeffs[0] + other.coeffs[0]
        b1 = self.coeffs[1] + other.coeffs[1]
        c1 = self.coeffs[2] + other.coeffs[2]
        newCoeffs = [a1, b1, c1]
        return Polynomial(newCoeffs)

    def __sub__(self, other):
        a1 = self.coeffs[0] - other.coeffs[0]
        b1 = self.coeffs[1] - other.coeffs[1]
        c1 = self.coeffs[2] - other.coeffs[2]
        newCoeffs = [a1, b1, c1]
        return Polynomial(newCoeffs)

    def __getitem__(self, index):
        try:
            return self.coeffs[index]
        except IndexError:
            return 0.

    def length(self):
        for index, coeff in enumerate(reversed(list(self.coeffs))):
            if coeff != 0:
                break
        return len(self.coeffs)-index

    def __mul__(self, other):
        length = self.length() + other.length()
        newCoeffs = [sum(self[j]*other[i-j] for j in range(i+1)) for i in range(length)]
        return Polynomial(newCoeffs)

    def root(self):
        d = self.coeffs[1] ** 2 - 4 * self.coeffs[0] * self.coeffs[2]
        if d == 0:
            return -self.coeffs[1] / 2 * self.coeffs[0]
        elif d < 0:
            return None
        else:
            x1 = (-self.coeffs[1] + d ** 0.5) / 2 * self.coeffs[0]
            x2 = (-self.coeffs[1] - d ** 0.5) / 2 * self.coeffs[0]
            return (x1, x2)

p1 = Polynomial([4, 7, 2])
p2 = Polynomial([6, 1, -5])

print(p1)
print(p2)

print(p1.root())
print(p2.root())

print(p1 * p2)
print(p1 + p2)
print(p1 - p2)