/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isEvenOddTree = function(root) {
  const lasts = [];
  const helper = (p, level = 0) => {
    if (!p) {
      return true;
    }
    if ((level + p.val) % 2 === 0) {
      return false;
    }
    if (lasts[level] === undefined) {
      lasts[level] = (level % 2 === 1) ? Infinity : -1;
    }
    if ((level % 2 === 1 && lasts[level] - p.val <= 0) ||
        (level % 2 === 0 && lasts[level] - p.val >= 0)) {
      return false;
    }
    lasts[level] = p.val;
    let res = helper(p.left, level + 1);
    if (!res) {
      return res;
    }
    res = helper(p.right, level + 1);
    return res;
  };
  return helper(root);
};