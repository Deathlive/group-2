class Person(object):
    def __init__(self, first, last, age):
        self.first = first
        self.last = last
        self.age = age
    
    def __str__(self):
        return "___Person___" + "\nFirstName: " + str(self.first) + "\nLastName: " + str(self.last) + "\nAge: " + str(self.age)

class Employee(Person):
    def __init__(self, first, last, age, staffnum):
        Person.__init__(self, first, last, age)
        self.staffnum = staffnum

    def __str__(self):
        return "\n___Person___" + "\nFirstName: " + str(self.first) + "\nLastName: " + str(self.last) + "\nAge: " + str(self.age) + "\nStaffNum: " + str(self.staffnum)


x = Person("Marge", "Simpson", 36)
y = Employee("Homer", "Simpson", 28, "Engineer")

print(x)
print(y)