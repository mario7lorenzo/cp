tbl = {}
def memoize(f, name):
	if name not in tbl:
		tbl[name] = {}
	memo = tbl[name]
	def helper(*args):
		if args in memo:
			return memo[args]
		else:
			results = f(*args)
			memo[args] = results
			return results
	return helper

def memo_fib(n):
	def helper(n):
		if n == 1 or n == 2:
			return 1
		else:
			return memo_fib(n - 1) + memo_fib(n - 2)
	return memoize(helper, "memo_fib")(n)

def main():
	return memo_fib(281474976710656)%(10**9)

if __name__ == '__main__':
	main()