def main():
	c = int(input())
	shares = [0 for _ in range(c)]
	events = []
	for i in range(c):
		k = int(input())

		for _ in range(k):
			n,d = [int(x) for x in input().split()]
			events.append((d,i,n))

	sorted_events = sorted(events)
	records = []
	for i in range(len(sorted_events)):
		event = sorted_events[i]
		company = event[1]
		n = event[2]

		shares[company] = n

		if i < len(sorted_events)-1 and event[0] < sorted_events[i+1][0]:
			records.append(sum(shares))

		if i == len(sorted_events)-1:
			records.append(sum(shares))


	records = [str(x) for x in records]
	print(' '.join(records))
	return

if __name__ == '__main__':
	main()