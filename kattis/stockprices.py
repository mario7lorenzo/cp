import heapq

def main():
	tc = int(input())

	for i in range(tc):
		asks = []
		bids = []

		trans = int(input())
		current_price = '-'
		for j in range(trans):
			inplst = input().split()
			reqtype = inplst[0]
			n = int(inplst[1])
			price = int(inplst[-1])

			if reqtype == 'buy':
				heapq.heappush(bids, (-price, n))
			else:
				heapq.heappush(asks, (price, n))


			while asks and bids and -bids[0][0] >= asks[0][0]:
				bid = heapq.heappop(bids)
				ask = heapq.heappop(asks)

				if bid[1] == ask[1]:
					current_price = ask[0]

				elif bid[1] < ask[1]:
					new_ask = (ask[0], ask[1] - bid[1])
					current_price = ask[0]
					heapq.heappush(asks, new_ask)
				else:
					new_bid = (bid[0], bid[1] - ask[1])
					current_price = ask[0]
					heapq.heappush(bids, new_bid)

			result = []

			if asks:
				result.append(str(asks[0][0]))
			else:
				result.append('-')

			if bids:
				result.append(str(-bids[0][0]))

			else:
				result.append('-')

			result.append(str(current_price))

			print(" ".join(result))

	return

if __name__ == '__main__':
	main()