def main():
	ln = int(input())
	a = input().split()
	a = [int(x) for x in a]
	counter = 0
	for i in range (1, ln+1):
		if counter >= 2:
			break
		if a[i] == a[i-1]:
			counter += 1 
	if counter == 2:
		print(0)
	elif counter == 1:
		print(1)
	else:
		print(len(a))
if __name__ == '__main__':
	main()