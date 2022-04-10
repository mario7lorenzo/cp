import heapq
from collections import deque

def main():
	n,t = [int(x) for x in input().split()]

	typetoval = {'S': 1, 'R': 2, 'F': 3}

	oq = deque()
	rq = deque()

	simq = []

	for _ in range(n):
		occurtime, eventtype, duration = input().split()
		occurtime = int(occurtime)
		duration = int(duration)

		simq.append((occurtime, typetoval[eventtype], duration))

	heapq.heapify(simq)

	otime = []
	rtime = []

	while simq:
		currtime, eventtype, misc = heapq.heappop(simq)

		if eventtype == typetoval['S']:
			if not t:
				oq.append((currtime, misc))
			else:
				t -= 1
				heapq.heappush(simq, (currtime + misc, typetoval['F'], ('S', currtime)))

		elif eventtype == typetoval['R']:
			if not t:
				rq.append((currtime, misc))
			else:
				t -= 1
				heapq.heappush(simq, (currtime + misc, typetoval['F'], ('R', currtime)))

		else:
			code, dropoff = misc

			if code == 'S':
				otime.append(currtime - dropoff)

			else:
				rtime.append(currtime - dropoff)

			if len(oq) > 0:
				dropoff, duration = oq.popleft()
				heapq.heappush(simq, (currtime + duration, typetoval['F'], ('S', dropoff)))
			elif len(rq) > 0:
				dropoff, duration = rq.popleft()
				heapq.heappush(simq, (currtime + duration, typetoval['F'], ('R', dropoff)))
			else:
				t += 1

	oavg = 0 if len(otime) == 0 else sum(otime)/len(otime)
	ravg = 0 if len(rtime) == 0 else sum(rtime)/len(rtime)

	print("%f %f" % (oavg, ravg))
	return

if __name__ == '__main__':
	main()