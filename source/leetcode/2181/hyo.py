class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head

        while cur :
            while cur.next.val > 0 :
                cur.val += cur.next.val
                cur.next = cur.next.next
            if not cur.next.next :
                cur.next = None
            cur = cur.next

        return head
