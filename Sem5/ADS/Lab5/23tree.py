class Node:
    def __init__(self, value, left=None, right=None, red=False):
        self.value = value
        self.left = left
        self.right = right
        self.red = red
    @staticmethod
    def red(node):
        return node and node.red
    def rotate_left(self):
        if not Node.red(self.left) and Node.red(self.right):
            child = self.right
            self.right, child.left = child.left, self
            self.red, child.red = True, self.red
            return child
        else:
            return self
    def rotate_right(self):
        if Node.red(self.left) and Node.red(self.left.left):
            child = self.left
            self.left, child.right = child.right, self
            self.red, child.red = True, self.red
            return child
        else:
            return self
    
    def flip_colors(self):
        if Node.red(self.left) and Node.red(self.right):
            self.red, self.left.red, self.right.red = \
                True, False, False
                
                
def insert(node, value, root=True):
    if not node:
        return Node(value, red=not root)
    
    # insert value
    if value == node.value:
        pass
    elif value < node.value:
        node.left = insert(node.left, value, root=False)
    else:
        node.right = insert(node.right, value, root=False)
    
    
    node = node.rotate_left()
    node = node.rotate_right()
    node.flip_colors()
    
    if root:
        node.red = False
    return node

root = None
for i in range(10):
    root = insert(root, i)
    
    
def preOrder(root): 

		if not root: 
			return

		print("{0} ".format(root.value), end="") 
		preOrder(root.left) 
		preOrder(root.right)

preOrder(root)
