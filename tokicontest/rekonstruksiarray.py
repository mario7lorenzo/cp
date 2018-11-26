def main():
	n, m = input().split()
	n = int(n)
	m = int(m)
	lst = input().split()
	lst = [int(x) for x in lst]
	counter = n%m
	dicti1 = {}
	dicti2 = {}
	for i in range (1, n+1):
		if i%m not in dicti1:
			dicti1[i%m] = [i]
		else:
			dicti1[i%m] += [i]
	for i in range (m):
		if i == 0:
			dicti2[i] = n//m
		else:
			if counter > 0:
				dicti2[i] = (n//m) + 1
				counter -= 1
			else:
				dicti2[i] = n//m
	saver = {}
	for i in range (len(lst)):
		if lst[i] not in saver:
			saver[lst[i]] = 1
		else:
			saver[lst[i]] += 1
	if dicti2 != saver:
		print(-1)
	else:
		isfirst = True
		for i in range (len(lst)):
			if i != len(lst)-1:
				temp = list(dicti1[lst[i]])
				x = temp.pop()
				dicti1[lst[i]] = temp
				print(x, end=" ")
			else:
				temp = list(dicti1[lst[i]])
				x = temp.pop()
				dicti1[lst[i]] = temp
				print(x)



if __name__ == '__main__':
	main()