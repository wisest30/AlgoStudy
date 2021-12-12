/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteMiddle = function(head) {
  if (head === null || head.next === null) {
    return null;
  }
  // const dummy = new ListNode(-1, head);
  let rabbit = head, turtle = head;
  while (rabbit.next !== null) {
    for (let i = 0; i < 2 && rabbit.next !== null; i++, rabbit = rabbit.next);
    if (rabbit.next === null) {
      turtle.next = turtle.next.next;
      break;
    }
    turtle = turtle.next;
  }
  return head;
};

