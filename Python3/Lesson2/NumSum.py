def sumDigits(num):
    return sum([int(i) for i in str(num)])

num = input("Enter number: ")
print(sumDigits(num))