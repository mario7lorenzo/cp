def main():
	n = int(input())
	heights = []

	for i in range(n):
		x = int(input())
		heights.append(x)

	heights_with_index = [(heights[i], i) for i in range(len(heights))]
	sorted_heights = sorted(heights_with_index)

	
	return

if __name__ == '__main__':
	main()