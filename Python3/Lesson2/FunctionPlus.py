def foo(a, b):
    sum = 0
    for i in range(a):
        sum = sum + b
    return sum

num1 = int(input("Enter num1: "))
num2 = int(input("Enter num2: "))
print( foo(num1, num2) )