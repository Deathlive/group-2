# 2
try:
    a = int(input("Enter number: "))
    b = 0
    summ = a / b
except ZeroDivisionError as err:
    print("Can't divide by zero:", err)