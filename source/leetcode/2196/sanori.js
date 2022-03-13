/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[][]} descriptions
 * @return {TreeNode}
 */
 var createBinaryTree = function(descriptions) {
  if (descriptions.length < 1) {
    return null;
  }
  const index = {};
  const parent = {};
  for ([p, c, isLeft] of descriptions) {
    if (index[c] === undefined) {
      index[c] = new TreeNode(c);
    }
    if (index[p] === undefined) {
      index[p] = new TreeNode(p);
    }
    if (isLeft) {
      index[p].left = index[c];
    } else {
      index[p].right = index[c];
    }
    parent[c] = p;
  }
  let cur = descriptions[0][0];
  while(parent[cur] !== undefined) {
    cur = parent[cur];
  }
  return index[cur];
};
