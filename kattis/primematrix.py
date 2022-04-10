def main():
	size = 1000000
	primes = [True for _ in range(size)]

	for i in range(2, size):
		if primes[i]:
			for j in range(i*i, size, i):
				primes[j] = False

	primes[0] = False
	primes[1] = False

	primeset = set()
	for i in range(size):
		if primes[i]:
			primeset.add(i)

	def is_prime(n):
		if n in primeset:
			return True

		for prime in primeset:
			if n%prime != 0:
				return False

		primeset.add(n)
		return True

	n, b = map(int, input().split())

	if n > 2 and n >= b:
		print('impossible')
		return

	if n == 2:
		print('1 2')
		print('2 1')
		return

	curr_lst = [i for i in range(1, n+1)]
	curr_idx = n-1

	minisum = sum(curr_lst)
	required = 0

	while not is_prime(minisum + required):
		required += 1

	maxi = (n * (2*b - n + 1))//2

	if maxi < minisum + required:
		print('impossible')
		return

	while required + curr_lst[curr_idx] > b - (n-1-curr_idx):
		required -= (b - (n-1-curr_idx)) - curr_lst[curr_idx]
		curr_lst[curr_idx] = b - (n-1-curr_idx)
		curr_idx -= 1
	curr_lst[curr_idx] += required
	curr_lst = [str(x) for x in curr_lst]

	for i in range(n):
		permutation = curr_lst[i:] + curr_lst[:i]
		print(' '.join(permutation))
	return

if __name__ == '__main__':
	main() 
