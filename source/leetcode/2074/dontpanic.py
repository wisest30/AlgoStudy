from copy import copy

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def printAllNodes(head: Optional[ListNode]):
    while head:
        print(head.val)
        head = head.next

class Solution:
    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]:
        result = None
        reshead = None

        # g = 1
        if head:
            reshead = copy(head)
            result = reshead
            head = head.next

        g = 2
        while head:
            gcnt = g

            stack = Deque()
            while head and gcnt > 0:
                stack.append(copy(head))
                head = head.next
                gcnt -= 1
            
            even = (g - gcnt) % 2 == 0

            while stack:
                reshead.next = stack.pop() if even else stack.popleft()
                reshead = reshead.next

            g += 1
        
        if reshead:
            reshead.next = None

        return result
