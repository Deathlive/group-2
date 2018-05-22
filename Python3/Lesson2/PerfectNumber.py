def checkPerfect(n):
    sum = 0
    for i in range(1, n):
        if n % i == 0:
            sum += i
    return sum == n

num = int(input("Enter num: "))
print(checkPerfect(num))