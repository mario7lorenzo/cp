from decimal import *
def main():
	a,b,c = [Decimal(x) for x in input().split()]
	print(a*b/c)
	return

if __name__ == '__main__':
	main()