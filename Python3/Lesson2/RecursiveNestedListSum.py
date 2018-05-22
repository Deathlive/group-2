def lsum(lst):
    total = 0
    for i in lst:
        if (type(i) == type([])):
            total += lsum(i)
        else:
            total += i
    return total

list1 = [[1, 2], 2, [3, 4], [5, 4]]
print( "Sum:", lsum(list1))