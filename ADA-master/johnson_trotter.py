'''a) Implement Johnson Trotter algorithm to generate permutations.
b) Given two text strings A of length n and B of length m, to transform A into B using a minimum number of operations of the following types: delete a character from A, insert a character into A, or change some character in A into a new character. The minimal number of such operations required to transform A into B is called the edit distance between A and B. For example, the edit distance(abbc, xbbacd) = 3 (change a to x; insert a after bb; insert d after c) Find a recurrence relation that is useful to find the edit distance of two strings A and B. Take an example of two strings of which one is your own name, and using this relation, fill the table for the minimum number of operations.'''
import math

class Node:
	def __init__(self, val):
		self.val = val + 1
		self.dir = 'left'
		#self.pos = val
	
	def print_val(self):
		print(str(self.val) + " Pointing to " + str(self.dir))


def find_larg_mobile(arr):
	max_ind = None
	for i in range(0, len(arr)):
		if arr[i].dir == 'left' and i == 0:
			continue
		if arr[i].dir == 'right' and i == len(arr) - 1:
			continue
			
			
		if arr[i].dir == 'left' and arr[i].val > arr[i-1].val:
			if max_ind == None:
				max_ind = i
			elif arr[max_ind].val < arr[i].val:
				max_ind = i
				
		
		if arr[i].dir == 'right' and arr[i].val > arr[i+1].val:
			if max_ind == None:
				max_ind = i
			elif arr[max_ind].val < arr[i].val:
				max_ind = i
	return max_ind

def swap(arr, i, j):
	temp = arr[i]
	arr[i] = arr[j]
	arr[j] = temp
	
	return arr
			
def JT(n):
	#array = [Node(4, 'left'), Node(3, 'left'), Node(1, 'left'), Node(2, 'left')]
	array = []
	for i in range(0, n):
		array.append(Node(i))
		array[i].print_val()
	print("\n")
		
	#printing all perms
	for i in range(math.factorial(n) - 1):
		print(i+2)
		inx = find_larg_mobile(array)
		print(array[inx].val)
		#change big value dir
		if array[inx].val < n:
			for i in range(0, n):
				if array[i].val > array[inx].val:
					if array[i].dir == 'left':
						array[i].dir = 'right'
					else:
						array[i].dir = 'left'
						
		if array[inx].dir == 'left':
			array = swap(array, inx, inx-1)  
			
		elif array[inx].dir == 'right':
			array = swap(array, inx, inx+1)
			
		#printing values each time
		for i in range(0, n):
			array[i].print_val()
		print("\n")
		
						
JT(6)
