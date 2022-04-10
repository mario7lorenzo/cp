def main():
	n = int(input())
	seed = [i for i in range(1, 10)]
	temp = []

	for i in range(2, n+1):
		for prev in seed:
			curr = prev*10
			while curr%i != 0:
				curr += 1

			for cand in range(curr, (prev+1)*10, i):
				temp.append(cand)

		seed = temp
		temp = []

	print(len(seed))
	return

if __name__ == '__main__':
	main()