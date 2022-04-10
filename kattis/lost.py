import heapq
from collections import deque
def main():
	n,m = [int(x) for x in input().split()]
	languages = input().split()

	langid = {}
	al = {}
	idd = 0

	for language in languages:
		langid[language] = idd
		idd += 1
		
	for i in range(105):
		al[i] = []

	for i in range(m):
		u,v,w = input().split()
		w = int(w)

		if u not in langid:
			langid[u] = idd
			idd += 1

		if v not in langid:
			langid[v] = idd
			idd += 1

		al[langid[u]].append((langid[v],w))
		al[langid[v]].append((langid[u],w))

	dist = []
	leng = []
	for i in range(105):
		dist.append(float('inf'))
		leng.append(float('inf'))

	q = deque()
	englishid = langid['English']
	dist[englishid] = 0
	leng[englishid] = 0
	is_visited = set()

	q.append(englishid)

	while q:
		u = q.popleft()
		if u in is_visited:
			continue
		is_visited.add(u)
		currdist = dist[u]
		currlen = leng[u]

		for nei in al[u]:
			v = nei[0]
			w = nei[1]

			if leng[v] >= currlen+1 and dist[v] >= w:
				if leng[v] == float('inf'):
					q.append(v)

				leng[v] = currlen+1
				dist[v] = w

	total = 0
	for language in languages:
		lid = langid[language]

		if (dist[lid] == float('inf')):
			print('Impossible')
			return

		total += dist[lid]

	print(total)
	return

if __name__ == '__main__':
	main()