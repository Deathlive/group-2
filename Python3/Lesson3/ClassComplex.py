class Complex(object):
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __str__(self):
        s = ""
        if self.a != 0:
            s += str(self.a)
        if self.b > 0:
            s += " + "
        else:
            s += " "
        if self.b != 0:
            s += str(self.b) + "i"
        elif len(s) == 0:
            s += "0"
        return s

    def __add__(self, other):
        real = self.a + other.a
        img = self.b + other.b
        return Complex(real, img)
    
    def __sub__(self, other):
        real = self.a - other.a
        img = self.b - other.b
        return Complex(real, img)

    def __mul__(self, other):
        real = (self.a * other.a) +  (-1 * self.b * other.b)
        img = (self.a * other.b) + (self.b * other.a)
        return Complex(real, img)

    def __truediv__(self, other):
        a = self.a
        b = self.b
        c = other.a
        d = other.b
        return Complex(float(a * c + b * d) / (c**2 + d**2),
                       float(b *c - a * d) / (c**2 + d**2))

    def __eq__(self, other):
        return self.a == other.a and self.b == other.b

    def __ne__(self, other):
        return not (self.a == other.a and self.b == other.b)
        
    def __lt__(self, other):
        return self.absolute() < other.absolute()

    def __gt__(self, other):
        return self.absolute() > other.absolute()

    def __le__(self, other):
        return self.absolute() <= other.absolute()

    def __ge__(self, other):
        return self.absolute() >= other.absolute()

    def __iadd__(self, other):
        self.a += other.a
        self.b += other.b
        return Complex(self.a, self.b)

    def __isub__(self, other):
        self.a -= other.a
        self.b -= other.b
        return Complex(self.a, self.b)

    def __imul__(self, other):
        self.a = self.a * other.a - self.b * other.b
        self.b = self.a * other.b + self.b * other.a
        return Complex(self.a, self.b)

    def __idiv__(self, other):
        self.a = (self.a * other.a + self.b * other.b) / (other.a ** 2 + other.b ** 2)
        self.b = (self.b * other.a - self.a * other.b) / (other.a ** 2 + other.b ** 2)
        return Complex(self.a, self.b)

    def __abs__(self):
        self.a = (self.a ** 2) ** 0.5
        self.b = (self.b ** 2) ** 0.5
        return self

    def absolute(obj):
        return (obj.a ** 2 + obj.b ** 2) ** 0.5

    def reverse(self):
        return Complex(self.a / self.absolute(), - (self.b / self.absolute()))

Complex1 = Complex(5, 4)
Complex2 = Complex(1, 2)

print(Complex1 + Complex2)
print(Complex1 - Complex2)
print(Complex1 * Complex2)
print(Complex1 / Complex2)

print()

print(Complex1 > Complex2)
print(Complex1 < Complex2)
print(Complex1 >= Complex2)
print(Complex1 <= Complex2)

print()

print(Complex1)
Complex1 += Complex2
print(Complex1)
Complex1 -= Complex2
print(Complex1)
Complex1 *= Complex2
print(Complex1)
Complex1 /= Complex2
print(Complex1)