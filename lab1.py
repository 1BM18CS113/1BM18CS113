
class ListNode:
   def __init__(self, val=0, next=None):
       self.val = val
       self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:

        cur = head
        count = 0

        while cur and count < k:
            cur = cur.next
            count += 1
 
        if count < k:
            return head
        
  
        cur = head
        temp = None
        prev = None
        count = 0

        while cur and count < k:
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp
            count += 1
        
  
        if cur:
     
            head.next = self.reverseKGroup(cur, k)
            
        return prev
        
        
def formList(val):
    node = ListNode(val)
    return node

root = formList(1)
root.next = formList(2)
root.next.next = formList(3)
root.next.next.next = formList(4)
root.next.next.next.next = formList(5)
root.next.next.next.next.next = formList(6)
root.next.next.next.next.next.next = formList(7)

curr = root
print("currentList = ")
while(curr != None):
    print(curr.val)
    curr = curr.next
    
reverseList = Solution()
revList = reverseList.reverseKGroup(root, 3)


curr = revList
print("RevList = ")
while(revList != None):
    print(revList.val)
    revList = revList.next