# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        carry = 0
        num = ""
        current_1 = l1
        current_2 = l2
        
        while current_1 is not None or current_2 is not None or carry != 0:
            sum = ((current_1.val if current_1 is not None else 0) + (current_2.val if current_2 is not None else 0) + carry)
            carry = 0
            num += str(sum%10)
            carry += 0 if sum < 10 else 1
            current_1 = current_1.next if current_1 is not None else None
            current_2 = current_2.next if current_2 is not None else None
            
        l3 = None
            
        for c in num[::-1]:
            l3 = ListNode(c, l3)
        
        return l3
