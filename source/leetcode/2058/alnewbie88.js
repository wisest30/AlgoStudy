/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var nodesBetweenCriticalPoints = function(head) {
    let prevNode = null;
    let curNode = head;
    let i = 0;
    let cpIndexes = [];
    do {
        const nextNode = curNode.next;
        if (prevNode && curNode && nextNode) {
            if ((curNode.val < prevNode.val && curNode.val < nextNode.val)
                || (curNode.val > prevNode.val && curNode.val > nextNode.val)) {
                cpIndexes.push(i);
            }
        }
        prevNode = curNode;
        curNode = curNode.next;
        i++;
    } while (curNode !== null);
    
    if (cpIndexes.length < 2) { // zero or one Critical Point
        return [-1, -1];
    }
    
    let minDist = 100000;
    let maxDist = cpIndexes[cpIndexes.length - 1] - cpIndexes[0];
    for (let i = 1; i < cpIndexes.length; i++) {
        const dist = cpIndexes[i] - cpIndexes[i - 1];
        minDist = Math.min(minDist, dist);
    }
    
    return [minDist, maxDist];
};
