from math import sqrt

limit = 30
result = []
for a in range(1, limit):
    for b in range(a+1, limit):
        s = a**2 + b**2
        C = sqrt(s)
        c = int(C)
        if c**2 == s and c < limit:
            result.append((a, b, c))
print(result)