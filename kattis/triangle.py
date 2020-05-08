import sys
from math import *

def main():
	case = 1
	for i in sys.stdin.readlines():
		it = int(i)
		circ = (3**(it+1)//2**(it))
		print("Case {}: {}".format(case, len(str(circ))))
		case += 1

if __name__ == '__main__':
	main()