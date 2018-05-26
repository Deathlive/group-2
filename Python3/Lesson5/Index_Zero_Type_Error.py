#5
try:
    List_1 = [1, 2, 4, 7, 3]
    List_2 = [3, 0, 4, 2, 1]

    for i in range(len(List_1)):
        res = List_1[i] / List_2[List_1[i]]
        print(res)
except IndexError as err:
    print("There is no such index in List_2:", err)
except ZeroDivisionError as err:
    print("Can't divide by zero:", err)
except TypeError as err:
    print("Wrong type divide:", err)