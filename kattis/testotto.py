def fn(n):
    if n == 0:
        return 1
    elif n == 1:
        return 2
    else:
        return 1 + fn(n-1) + fn(n-2)
print(fn(6))