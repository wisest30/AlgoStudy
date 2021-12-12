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
    let n = 0;
    let cur = head;
    while (cur && cur.val > 0) {
        n++;
        cur = cur.next;
    }
    
    let middleIdx = Math.floor(n / 2);
    if (middleIdx === 0) {
        return null;
    }
    
    let prevMiddleNode = undefined;
    let middleNode = head;
    for (let i = 0; i < middleIdx; i++) {
        prevMiddleNode = middleNode;
        middleNode = middleNode.next;
    }
    
    prevMiddleNode.next = middleNode.next;
    return head;
};
