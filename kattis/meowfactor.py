from math import *

def main():
	n = int(input())
	k = int(n**(1/9))
	for x in range (k+1, 0, -1):
		if (n%x**9==0):
			print(x)
			break


if __name__ == '__main__':
	main()