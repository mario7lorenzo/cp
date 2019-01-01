def main():
	many = int(input())
	lst = []
	for i in range (many):
		x = input()
		lst.append(x)
	bell = 0
	lst.reverse()
	for i in range (len(lst)):
		if lst[i] == "O":
			bell += 2**i
	print(bell)

if __name__ == '__main__':
	main()