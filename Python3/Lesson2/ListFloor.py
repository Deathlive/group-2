import math

def sumFloor(lst):
    for i in range(len(lst)):
        lst[i] = math.floor(lst[i])
    return sum(lst)

spam = [5.2, 1.7, 8.4, 3.9, 1.5, 2.5]
print(sumFloor(spam))