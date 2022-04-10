def main():
	n = int(input())
	students = [int(x) for x in input().split()]

	bjorn = students.index(0)
	students.remove(0)
	students.append(0)

	curr_hap = sum([(i+1)*students[i] for i in range(len(students))])
	maxi = curr_hap

	for i in range(len(students)-1,-1,-1):
		curr_hap += students[i]
		maxi = max(maxi, curr_hap)

	print(maxi)
	return

if __name__ == '__main__':
	main()