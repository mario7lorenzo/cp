def main():
	r,c,f,s,g = [int(x) for x in input().split()]

	faculties_coordinates = []
	students_to_faculties = []
	for i in range(f):
		inp = [int(x) for x in input().split()]
		formatted = []
		for j in range(inp[0]):
			row = inp[2*j + 1]
			col = inp[2*j + 2]
			formatted.append((row,col))

		formatted.sort()
		faculties_coordinates.append(formatted)


	for i in range(f):
		students_to_faculties.append([])

	for i in range(s):
		row,col,idd,fac = [int(x) for x in input().split()]
		students_to_faculties[fac-1].append((idd,row,col))

	threshold = [int(x) for x in input().split()]
	# sort students
	for faculty in students_to_faculties:
		faculty.sort(key = lambda x: x[0])

	min_faculty = []

	for i in range(f):
		distances = []
		students = students_to_faculties[i]
		assigned = faculties_coordinates[i]
		# print("faculty" + str(i))
		for j in range(len(students)):
			student = students[j]
			ass = assigned[j]
			sr = student[1]
			sc = student[2]
			ar = ass[0]
			ac = ass[1]
			# print("id:" + str(student[0]))
			distances.append(abs(sr-ar) + abs(sc-ac))

		move_required = max(0, threshold[i] - distances.count(0))
		# print(move_required)
		filtered_zero = [x for x in distances if x > 0]
		filtered_zero.sort()

		steps = sum(filtered_zero[:move_required])
		min_faculty.append(steps)

	min_faculty.sort()
	print(sum(min_faculty[:g]))
	return

if __name__ == '__main__':
	main()