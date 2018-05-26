# 1
try:
    num = input("Enter number: ")
    num = int(num)
except ValueError as err:
    print("Could not convert to a number:", err)