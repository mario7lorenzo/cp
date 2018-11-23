def main():
	octal = input()
	dec = 0
	for i in range (len(octal)):
		dec += int(octal[i]) * (8**(len(octal) - i - 1))
	lst = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
	hexa = ""
	while (dec != 0):
		hexa += lst[dec%16]
		dec = dec // 16
	hexa = hexa[::-1]
	if octal == "0":
		print(0)
	else:
		for i in range (len(hexa)):
			if hexa[i] != 0:
				x = i
				break
		hexa = hexa[i:]
		print(hexa)

if __name__ == '__main__':
	main()