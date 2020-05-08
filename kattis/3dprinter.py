statues = input()
def no_of_days(x):
    printer, day = 1, 0
    while int(printer) < int(statues):
        printer = 2 * printer
        day = day + 1
    return day + 1
n = no_of_days(int(statues))
print(n)