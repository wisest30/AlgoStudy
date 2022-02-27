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
var mergeNodes = function(head) {
    let start = head;   // start of merge
    let cur = head.next;
    let sum = 0;
    while (cur) {
        if (cur.val === 0) {
            cur.val = sum;
            start.next = cur;
            start = cur;
            sum = 0;
        } else {
            sum += cur.val;
        }
        
        cur = cur.next;
    }
    
    head = head.next;
    return head;
};
