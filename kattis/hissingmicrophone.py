z = input()
def hiss(a):
    x, m, n = 0, "", ""
    is_hiss = False
    while (x < (int(len(str(a)))-1)):
        m = a[x]
        n = a[x + 1]
        if m == n == 's':
            is_hiss = True
        x = x + 1
    if is_hiss == True:
        return 'hiss'
    else:
        return 'no hiss'
b = hiss(z)
print(b)