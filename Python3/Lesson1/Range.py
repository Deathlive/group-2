num = list(range(1500, 2701))

for j in num:
    if j % 5 == 0 and j % 7 == 0:
        print(j, end=' ')
