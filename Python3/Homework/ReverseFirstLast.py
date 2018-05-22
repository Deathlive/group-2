var = input("Enter text: ")
var = var[-1:] + var[1:-1] + var[:1]
print(var)
