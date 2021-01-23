/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var swapNodes = function(head, k) {
  let n = 0;
  for (let p = head; p; p = p.next, n++);
  if (k > n / 2) {
    k = n - k + 1;
  }
  // console.log({n, k})
  let p = head, i = 0;
  for (; i < k-1; i++, p = p.next);
  const a = p;
  for (; i < n - k; i++, p = p.next);
  const b = p;
  const tmp = b.val;
  b.val = a.val;
  a.val = tmp;
  return head;
};
