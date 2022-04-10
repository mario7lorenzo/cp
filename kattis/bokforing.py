def main():
	n,q = [int(x) for x in input().split()]

	wealths = [[0, 0] for _ in range(n)]
	lazy = [-1, 0]

	for i in range(q):
		rawinp = input().split()
		command = rawinp[0]

		if command == 'SET':
			person = int(rawinp[1]) - 1
			val = int(rawinp[2])
			wealths[person] = [i,val]

		elif command == 'RESTART':
			val = int(rawinp[1])
			lazy = [i, val]

		else:
			person = int(rawinp[1]) - 1
			curr = wealths[person]
			lastupdated = curr[0]

			if lastupdated > lazy[0]:
				print(curr[1])

			else:
				print(lazy[1])
	return

if __name__ == '__main__':
	main()