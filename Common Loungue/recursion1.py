
def f(x, y):
    # base case
    if (y == 0):
        return 1

    if (y%2 == 0):
        return f(x, y/2) ** 2 % 41

    if (y%2 == 1):
        return x * f(x, y/2) ** 2 % 41

print(f(14, 98765432123456789))