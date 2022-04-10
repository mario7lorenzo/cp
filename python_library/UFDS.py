class UFDS:
	def __init__(self, n):
		self.parents = []
		self.ranks = []
		self.size_of_set = []
		self.num_of_set = n

		for i in range(n):
			self.parents.append(i)
			self.ranks.append(0)
			self.size_of_set.append(1)

	def find_set(self, x):
		if self.parents[x] == x:
			return x
		else:
			value = self.find_set(self.parents[x])
			self.parents[x] = value
			return value

	def is_same_set(self, x, y):
		return self.find_set(x) == self.find_set(y)

	def union_set(self, m, n):
		if not self.is_same_set(m,n):
			self.num_of_set -= 1
			x = self.find_set(m)
			y = self.find_set(n)

			if self.ranks[x] > self.ranks[y]:
				self.parents[y] = x
				self.size_of_set[x] += self.size_of_set[y]

			else:
				self.parents[x] = y
				self.size_of_set[y] += self.size_of_set[x]

				if self.ranks[x] == self.ranks[y]:
					self.ranks[y] += 1

	def num_of_disjoint_sets(self):
		return self.num_of_set

	def size_of_sets(self, x):
		return self.size_of_set[find_set(x)]
