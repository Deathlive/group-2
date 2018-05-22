num = int(input("Enter num: "))

a = 0
b = 1
fib = [a, b]

while num > 1:
    fibadd = fib[a] + fib[b]
    fib.append(fibadd)
    a += 1
    b += 1
    num -= 1

print(fib)