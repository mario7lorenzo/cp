def main():
	lst = []
	for i in range (10):
		x = input()
		y = int(x)%42
		if y not in lst:
			lst.append(y)
	print(len(lst)) 


if __name__ == '__main__':
	main()