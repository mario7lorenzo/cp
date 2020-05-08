dicti = {}
def fac():
	lst = []
	for i in range (10001):
		lst.append(1)
		if (i == 0 or i == 1):
			dicti[i] = 1
	for i in range (2, 10001):
		lst[i] = i*lst[i-1]
		dicti[i] = lst[i]

def main():
	fac()
	n = int(input())
	for i in range (n):
		x = int(input())
		catalan = dicti[2*x]//(dicti[x+1]*dicti[x])
		print(catalan)

if __name__ == '__main__':
	main()

