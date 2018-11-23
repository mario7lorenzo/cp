tbl = {}
def memoize(f, name):
	if name not in tbl:
		tbl[name] = {}
	memo = tbl[name]
	def helper(*args):
		if args in memo:
			return memo[args]
		else:
			result = f(*args)
			memo[args] = result
			return result
	return helper

def memo_fac(n):
	def helper(n):
		if n == 0 or n == 1:
			return 1
		else:
			return n * memo_fac(n - 1)
	return memoize(helper, "memo_fac")(n)

def main():
	contents = []
	while True:
		try:
			line = input()
		except EOFError:
			break
		contents.append(line)
	for i in range (len(contents)):
		dicti = {}
		for j in range (len(contents[i])):
			if contents[i][j] not in dicti:
				dicti[contents[i][j]] = 1
			else:
				dicti[contents[i][j]] += 1
		panjang = len(contents[i])
		final = memo_fac(panjang)
		lst = list(dicti.values())
		for j in range (len(lst)):
			if lst[j] > 1:
				final = final // memo_fac(lst[j])
		print(final)

if __name__ == '__main__':
	main()