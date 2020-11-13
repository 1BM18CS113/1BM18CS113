class Node:
    def __init__(self,val): 
        self.val = val 
        self.left = None
        self.right = None        
        self.elecount = 1         
        self.lcount = 0
 
class Tree: 
    def __init__(self,root): 
        self.root = root 
    #construct avl tree
    def insert(self,node):
        balance = None         
        curr = self.root 
        cnt = 0
        #perform balancing of tree
        self.avlOperations(balance, self.root.val, self.root)
        while curr!=None: 
            prev = curr 
            if node.val>curr.val: 
                cnt += (curr.elecount+curr.lcount) 
                curr=curr.right 
            elif node.val<curr.val: 
                curr.lcount+=1
                curr=curr.left 
            else: 
                prev=curr 
                prev.elecount+=1
                break
        if prev.val>node.val: 
            prev.left = node 
        elif prev.val<node.val: 
            prev.right = node 
        else: 
            return cnt+prev.lcount 
        return cnt 


    def avlOperations(self, balance, key, root):      
      if balance:
        root.height = 1 + max(self.getHeight(root.left), 
              self.getHeight(root.right)) 

        if balance > 1 and key < root.left.val: 
          return self.rightRotate(root) 


        if balance < -1 and key > root.right.val: 
          return self.leftRotate(root) 

      
        if balance > 1 and key > root.left.val: 
          root.left = self.leftRotate(root.left) 
          return self.rightRotate(root) 

      
        if balance < -1 and key < root.right.val: 
          root.right = self.rightRotate(root.right) 
          return self.leftRotate(root) 

    def leftRotate(self, z): 

      y = z.right 
      T2 = y.left 

      y.left = z 
      z.right = T2 
      z.height = 1 + max(self.getHeight(z.left), 
              self.getHeight(z.right)) 
      y.height = 1 + max(self.getHeight(y.left), 
              self.getHeight(y.right)) 
      return y

    def rightRotate(self, z): 

      y = z.left 
      T3 = y.right 
    
      y.right = z 
      z.left = T3 

      z.height = 1 + max(self.getHeight(z.left), 
              self.getHeight(z.right)) 
      y.height = 1 + max(self.getHeight(y.left), 
              self.getHeight(y.right)) 
      return y 
    
    def getHeight(self, root): 
      if not root: 
        return 0

      return root.height 

    def getBalance(self, root): 
      if not root: 
        return 0

      return self.getHeight(root.left) - self.getHeight(root.right) 
 
def constructArray(arr,n): 
    t = Tree(Node(arr[-1])) 
    ans = [0] 
    for i in range(n-2,-1,-1): 
        ans.append(t.insert(Node(arr[i]))) 
    return reversed(ans) 
 
   
def main(): 
    
    arr = [1, 2, 3, 4, 5] 
    n = len(arr)

    print("the input array is :")
    for i in arr:
      print(i)
    
    print("the output array is :")
    a = constructArray(arr, n)
    for i in a:
      print(i)

main()