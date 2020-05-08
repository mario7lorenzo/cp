dicti = {}
def factorial(x, curr):
	if curr < x:
		if x == 0 or x == 1:
			dicti[x] = 1
		else:
			temp = x*dicti[x-1]
			dicti[x] = temp
	return dicti[x]

def main():
	x = int(input())
	counter = 0
	curr = -1
	for i in range (x+1):
		counter += 1/factorial(i, curr)
		curr += 1
	print(counter)

if __name__ == '__main__':
	main()