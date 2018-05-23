import math

class Circle(object):
    def __init__(self, radius):
        self.radius = radius

    def __str__(self):
        return "Circle Radius: " + str(self.radius)

    def setRadius(self, newRadius):
        self.radius = newRadius

    def getArea(self):
        return self.radius * self.radius * math.pi

    def getPerimeter(self):
        return 2 * math.pi * self.radius;

Circle1 = Circle(5)
print(Circle1)
print("Circle Area: " + str(Circle1.getArea()))
print("Circle Radius: " + str(Circle1.getPerimeter()))