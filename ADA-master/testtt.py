
                
                


def knapSack(W , weight , value , n): 
  
    if n == 0 or W == 0 : 
        return 0
  
 
    if (weight[n-1] > W): 
        return knapSack(W , weight , value , n-1) 
  

    else: 
        return max(value[n-1] + knapSack(W-weight[n-1] , weight , value , n-1), knapSack(W , weight , value , n-1)) 
  
 

value = [6, 10, 12, 14, 16] 
weight = [1, 2, 3, 4, 5] 
W = 50
n = len(value) 
# print(knapSack(W , weight , value , n))




# PART 2


def max(a, b): 
    if(a > b): 
        return a 
    return b 
      
 
def palin(seq, i, j): 
      
    if (i == j): 
        return 1
  
 
    if (seq[i] == seq[j] and i + 1 == j): 
        return 2
      
    if (seq[i] == seq[j]): 
        return palin(seq, i + 1, j - 1) + 2
  
  
    return max(palin(seq, i, j - 1),  
               palin(seq, i + 1, j)) 
  


sequence = "MayDayMayDay"
n = len(sequence) 
print("The length of the LPS is",palin(sequence, 0, n - 1)) 
    
