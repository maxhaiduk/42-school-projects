#!/usr/bin/python

class push_swap:

	"""
	Class push_swap contains two stack: a & b and method for operating
	"""

	def __init__(self, initail_stack):
		self.a = initail_stack
		self.b = []

	def operate(self, tool):
		if (tool == 'sa'):
			self.a[0], self.a[1] = self.a[1], self.a[0]
		elif (tool == 'sb'):
			self.b[0], self.b[1] = self.b[1], self.b[0]
		elif (tool == 'ss'):
			self.a[0], self.a[1] = self.a[1], self.a[0]
			self.b[0], self.b[1] = self.b[1], self.b[0]
		elif (tool == 'pa'):
			self.a.insert(0, self.b.pop(0))
		elif (tool == 'pb'):
			self.b.insert(0, self.a.pop(0))
		elif (tool == 'ra'):
			self.a.append(self.a.pop(0))
		elif (tool == 'rb'):
			self.b.append(self.b.pop(0))
		elif (tool == 'rr'):
			self.a.append(self.a.pop(0))
			self.b.append(self.b.pop(0))
		elif (tool == 'rra'):
			self.a.insert(0, self.a.pop(len(self.a) - 1))
		elif (tool == 'rrb'):
			self.b.insert(0, self.b.pop(len(self.b) - 1))
		elif (tool == 'rrr'):
			self.a.insert(0, self.a.pop(len(self.a) - 1))
			self.b.insert(0, self.b.pop(len(self.b) - 1))


if __name__ == "__main__":
	ps = push_swap([3, 2, 1, 0])
	ps.operate("pb")
	ps.operate('pb')
	ps.operate('ss')
	print(ps.a)
	print(ps.b)
