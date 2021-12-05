class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        n = 0
        cur = head
        while cur :
            cur = cur.next
            n += 1
        
        if n == 1 :
            return None

        i = 0
        cur = head
        while cur :
            if i == n // 2 - 1 :
                cur.next = cur.next.next

            cur = cur.next
            i += 1
        
        return head
            
