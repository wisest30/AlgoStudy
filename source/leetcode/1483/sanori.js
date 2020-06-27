/**
 * @param {number} n
 * @param {number[]} parent
 */
var TreeAncestor = function(n, parent) {
  this.parents = parent;
};

/** 
 * @param {number} node 
 * @param {number} k
 * @return {number}
 */
TreeAncestor.prototype.getKthAncestor = function(node, k) {
  let cur = node;
  while (k > 0 && cur > -1) {
    cur = this.parents[cur];
    k--;
  }
  return cur;
};