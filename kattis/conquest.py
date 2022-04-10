import heapq

def main():
	n,m = [int(x) for x in input().split()]
	armies = {}
	al = {}

	for i in range(1,n+1):
		al[i] = []
	
	for _ in range(m):
		u,v = [int(x) for x in input().split()]
		al[u].append(v)
		al[v].append(u)

	for i in range(1, n+1):
		s = int(input())
		armies[i] = s

	q = [(armies[1], 1)]
	curr_army = armies[1]
	is_conquested = set()

	while q:
		tobeconquested = heapq.heappop(q)
		army = tobeconquested[0]
		island = tobeconquested[1]

		if island in is_conquested:
			continue

		if island != 1 and army >= curr_army:
			break

		is_conquested.add(island)
		if island != 1:
			curr_army += army

		for nei in al[island]:
			heapq.heappush(q, (armies[nei], nei))

	print(curr_army)
	return

if __name__ == '__main__':
	main()