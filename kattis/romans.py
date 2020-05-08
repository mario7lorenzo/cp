def main():
	x = float(input())
	x *= 1000*(5280/4854)
	x = int(round(x))
	print(x)

if __name__ == '__main__':
	main()