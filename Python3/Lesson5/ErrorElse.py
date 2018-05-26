# 4
try:
    num = int(input("Enter number: "))
except ValueError as err:
    print("The input must be an integer:", err)
else:
    if num % 3 == 0:
        print("Perfect!")
    else:
        raise NameError("The %d must be divisible by 3, without residue" % (num))