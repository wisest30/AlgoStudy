/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var mergeNodes = function(head) {
  if (!head) {
    return head;
  }
  const res = new ListNode(0);
  let p = head.next, q = res;
  while (p) {
    while(p.val !== 0) {
      q.val += p.val;
      p = p.next;
    }
    if (p.next !== null) {
      q.next = new ListNode(0);
      q = q.next;
    }
    p = p.next;
  }
  
  return res;
};
