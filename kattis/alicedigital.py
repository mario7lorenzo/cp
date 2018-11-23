testcase = input()
for i in range (int(testcase)):
	n, m = input().split(' ')
	for j in range(n):
		x = input()
		lst = []
		lst2 = []
		maxi = -99999999
		counter = 0
		occurences = 0
		if x < m:
			maxi = max(sum(lst), maxi)
			lst = []
			lst2 = []
			counter = 0
		if (x == m):
			lst.append(x)
			lst2.append(x)
			maxi = max(sum(lst), maxi)
			lst = lst2
			lst2 = [x]
			counter += 1
			occurences += 1
		else:
			lst.append(x)
			lst2.append(x)
		if (m not in lst):
			print(maxi)
		else:
			maxi = max(sum(lst), maxi)
			print(maxi)

