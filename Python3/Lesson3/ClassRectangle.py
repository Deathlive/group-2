class Rectangle(object):
    def __init__(self, length, width):
        self.length = length
        self.width = width

    def __str__(self):
        return "Rectangle L x W: " + str(self.length) + " x " + str(self.width)
        
    def getArea(self):
        return self.length * self.width
		
    def getPerimeter(self):
        return 2*(self.length + self.width)

rect1 = Rectangle(5,4)
rect2 = Rectangle(20,100)

print("%s - Area = %d and Perimeter = %d." % (rect1, rect1.getArea(), rect1.getPerimeter()))
print("%s - Area = %d and Perimeter = %d." % (rect2, rect2.getArea(), rect2.getPerimeter()))