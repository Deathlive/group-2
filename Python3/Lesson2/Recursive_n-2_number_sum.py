def sumNum(number):
    if number <= 0:
        return 0
    return number + sumNum(number - 2)

num = int(input("Enter number: "))
if num >= 0:
    print("Sum:", sumNum(num))
else:
    print("Enter correct number...")