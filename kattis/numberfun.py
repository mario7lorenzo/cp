def main():
	testcase = int(input())
	for i in range (testcase):
		lst = input().split()
		a = int(lst[0])
		b = int(lst[1])
		f = int(lst[2])
		if (a+b==f) or (a-b==f) or (b-a==f) or (a*b==f) or (a/b==f) or (b/a==f):
			print("Possible")
		else:
			print("Impossible")

if __name__ == '__main__':
	main()