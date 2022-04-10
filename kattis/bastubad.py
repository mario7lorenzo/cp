def eval_quad(a,b,c,x):
	return a*(x**2) + b*x + c

def main():
	n = int(input())
	finns = []

	for _ in range(n):
		a,b,c,t = [float(x) for x in input().split()]
		finns.append((t,a,b,c))

	finns.sort(reverse = True)

	atot = 0.0
	btot = 0.0 
	ctot = 0.0
	happiness = 0.0

	for finn in finns:
		t,a,b,c = finn
		atot += a
		btot += b
		ctot += c

		cand1 = eval_quad(atot,btot,ctot,0.0)
		cand2 = eval_quad(atot,btot,ctot,t)

		cand3 = 0.0
		if atot != 0:
			extrema = -0.5*btot/atot
			if extrema > 0.0 and extrema < t:
				cand3 = eval_quad(atot,btot,ctot,extrema)

		happiness = max(happiness,cand1,cand2,cand3)

	print(happiness)
	return

if __name__ == '__main__':
	main()