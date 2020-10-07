

import random 

class Node(object): 
	
	def __init__(self, key, level): 
		self.key = key 

		
		self.forward = [None]*(level+1) 

class SkipList(object): 

	def __init__(self, max_lvl, P): 
		
		self.MAXLVL = max_lvl 


		self.P = P 


		self.header = self.createNode(self.MAXLVL, -1) 

	
		self.level = 0
	
	# create new node 
	def createNode(self, lvl, key): 
		n = Node(key, lvl) 
		return n 
	

	def randomLevel(self): 
		lvl = 0
		while random.random()<self.P and lvl<self.MAXLVL:lvl += 1
		return lvl 

	def insertElement(self, key): 
	
		update = [None]*(self.MAXLVL+1) 
		current = self.header 


		for i in range(self.level, -1, -1): 
			while current.forward[i] and current.forward[i].key < key: 
				current = current.forward[i] 
			update[i] = current 

	
		current = current.forward[0] 


		if current == None or current.key != key: 
	
			rlevel = self.randomLevel() 

	
			if rlevel > self.level: 
				for i in range(self.level+1, rlevel+1): 
					update[i] = self.header 
				self.level = rlevel 

			
			n = self.createNode(rlevel, key) 

			for i in range(rlevel+1): 
				n.forward[i] = update[i].forward[i] 
				update[i].forward[i] = n 

			print("Successfully inserted key {}".format(key)) 

	def deleteElement(self, search_key): 

		
		update = [None]*(self.MAXLVL+1) 
		current = self.header 

	
		for i in range(self.level, -1, -1): 
			while(current.forward[i] and current.forward[i].key < search_key): 
				current = current.forward[i] 
			update[i] = current 

		
		current = current.forward[0] 

	
		if current != None and current.key == search_key: 

			
			for i in range(self.level+1): 

				
				if update[i].forward[i] != current: 
					break
				update[i].forward[i] = current.forward[i] 

		
			while(self.level>0 and self.header.forward[self.level] == None): 
				self.level -= 1
			print("Successfully deleted {}".format(search_key)) 

	def searchElement(self, key): 
		current = self.header 

		
		for i in range(self.level, -1, -1): 
			while(current.forward[i] and current.forward[i].key < key): 
				current = current.forward[i] 


		current = current.forward[0] 


		if current and current.key == key: 
			print("Found key ", key) 


	def displayList(self): 
		print("\n*****Skip List******") 
		head = self.header 
		for lvl in range(self.level+1): 
			print("Level {}: ".format(lvl), end=" ") 
			node = head.forward[lvl] 
			while(node != None): 
				print(node.key, end=" ") 
				node = node.forward[lvl] 
			print("") 


def main(): 
	lst = SkipList(3, 0.5) 
	lst.insertElement(3) 
	lst.insertElement(6) 
	lst.insertElement(7) 
	lst.insertElement(9) 
	lst.insertElement(12) 
	lst.insertElement(19) 
	lst.insertElement(17) 
	lst.insertElement(26) 
	lst.insertElement(21) 
	lst.insertElement(25) 
	lst.displayList() 

	# Search  19 
	lst.searchElement(19) 

	# Delete  19 
	lst.deleteElement(19) 
	lst.displayList() 

main() 
