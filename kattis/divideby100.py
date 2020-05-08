def main():
	a = input()
	b = input()
	if (len(a) == len(b)):
		a = "0." + a
	elif (len(b) > len(a)):
		a = "0." + '0'*(len(b)-len(a)-1) + a
	else:
		a = a[:len(a)-len(b)+1] + '.' + a[len(a)-len(b)+1:]
	pointer = len(a)
	while a[pointer-1] == '0':
		pointer -= 1
	if a[pointer-1] == '.':
		pointer -= 1
	print(a[:pointer])


if __name__ == '__main__':
	main()