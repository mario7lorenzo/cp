from math import *

def main():
	m, n, t = input().split(' ')
	if t == 1:
		perform = factorial(n)
		if (m >= perform):
			print("AC")
		else:
			print("TLE")
	else if t == 2:
		

if __name__ == '__main__':
	main()

