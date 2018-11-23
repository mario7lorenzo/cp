def main():
	lst = input().split()
	dicti = {}
	for i in lst:
		if i not in dicti:
			dicti[i] = 1
		else:
			dicti[i] += 1
	lis = list(dicti.values())
	verify = True
	for i in lis:
		if i > 1:
			verify = False
			break
	if verify:
		print("yes")
	else:
		print("no")

if __name__ == '__main__':
	main()