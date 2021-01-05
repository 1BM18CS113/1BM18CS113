def display_hash(hashTable): 
      
  for i in range(len(hashTable)): 
    print(i, end = " ") 
      
    for j in hashTable[i]: 
        print("-->", end = " ") 
        print(j, end = " ")           
    print() 
  
HashTable = [[] for _ in range(10)] 
  
def Hashing(keyvalue): 
    return keyvalue % len(HashTable) 


def secondHighest(a):
  hash_table = {}
  for ele in a:
    if ele not in hash_table.keys():
      hash_table[ele] = 1
    else:
      hash_table[ele] += 1

  max_freq = max(hash_table.values())
  second_highest_freq = 0
  for i in hash_table.values():
    if second_highest_freq < i and i < max_freq:
      second_highest_freq = i

  second_highest_freq_STRING = ''
  for string, count in hash_table.items():
    if count == second_highest_freq:
      second_highest_freq_STRING = string


  return second_highest_freq_STRING

def main():
  n = int(input("Enter number of Strings : "))

  a = list(map(str, input("Enter the Strings separeted by a space : ").strip().split()))[:n] 

  print("The String with secons highest frequency is \'", secondHighest(a), '\'')

main()



#aaa, abg, dab, tyx, dab, aaa, aaa, abg