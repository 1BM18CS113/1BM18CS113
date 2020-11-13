from collections import defaultdict

class Graph: 
  
    
    def __init__(self,vertices): 
  
        self.V = vertices 
        self.graph = defaultdict(list) 
  
    def addEdge(self,u,v,w): 
        self.graph[u].append((v,w)) 
  
     
    def DLS(self,src,target,maxDepth,parent): 
  
        if src == target : return 0
  
        
        if maxDepth <= 0 : return -1

        res=10000
        nextnode=src
        for node,weight in self.graph[src]: 
                p=self.DLS(node,target,maxDepth-1,parent)
                if(p!=-1): 
                    if(p<res):
                        res=p+weight
                        nextnode=node
        parent[src]=nextnode           
        return res
  
    
    def IDDFS(self,src, target, maxDepth): 
        ans=1000
        
        parent = [0] * 8
        for i in range(maxDepth+1): 
            if self.DLS(src, target, i,parent)!=-1:
                ans=min(ans,self.DLS(src, target, i,parent))
        print(parent);
        i = 0
        print(i)
        while i < 7:
            print(parent[i])
            i = parent[i]

        return ans
  

g = Graph(8) 
g.addEdge(0, 1, 3) 
g.addEdge(0, 2, 2) 
g.addEdge(0, 3, 1) 
g.addEdge(1, 4, 6) 
g.addEdge(2, 5, 4) 
g.addEdge(3, 7, 20) 
g.addEdge(4, 6, 1) 
g.addEdge(5, 7, 8) 
g.addEdge(6, 7, 1) 
parent = [0] * 10 
target = 7; maxDepth = 4; src = 0
ans=g.IDDFS(src, target, maxDepth)
if ans != 1000: 
    
    print("The optimal cost is = ",ans)
else : 
    print ("")

