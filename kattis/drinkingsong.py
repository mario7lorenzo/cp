def main():
	n = int(input())
	word = input()

	for i in range (n,1,-1):
		print(str(i) + " bottles of " + word + " on the wall, " + str(i) + " bottles of " + word + ".")

		if i == 2:
			print("Take one down, pass it around, " + str(i-1) + " bottle of " + word + " on the wall.")
		else:
			print("Take one down, pass it around, " + str(i-1) + " bottles of " + word + " on the wall.")

		print("")

	print("1 bottle of " + word + " on the wall, 1 bottle of " + word + ".")
	print("Take it down, pass it around, no more bottles of " + word + ".")
	return

if __name__ == '__main__':
	main()