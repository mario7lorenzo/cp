def main():
	testcase = int(input())
	for i in range (testcase):
		lst = input().split()
		sets = lst.pop(0)
		counter = 0
		for i in range (len(lst)):
			if i > 0:
				j = i - 1
				val = lst[i]
				# print("ini val skrg")
				# print(val)
				verifier = False
				while (j >= 0):
					if int(val) < int(lst[j]):
						counter += 1
					else:
						verifier = True
						lst = lst[0:j+1] + [val] + lst[j+1:i] + lst[i+1:]
						# print("ini lst skrg")
						# print(lst)
						break
					# print("ini counter")
					# print(counter)
					j -= 1
				if not verifier:
					lst = [val] + lst[0:i] + lst[i+1:]
		print(sets + " " + str(counter))


if __name__ == '__main__':
	main()