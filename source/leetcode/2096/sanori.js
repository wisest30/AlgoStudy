/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} startValue
 * @param {number} destValue
 * @return {string}
 */
var getDirections = function(root, startValue, destValue) {
  const path = (target, u = root, dirs=[]) => {
    if (u.val === target) {
      return dirs;
    }
    let res = null;
    if (u.left) {
      dirs.push('L');
      res = path(target, u.left, dirs);
      if (res) {
        return res;
      }
      dirs.pop();
    }
    if (u.right) {
      dirs.push('R');
      res = path(target, u.right, dirs);
      if (res) {
        return res;
      }
      dirs.pop();
    }
    return null;
  };
  
  const destPath = path(destValue);
  const startPath = path(startValue);
  // console.log({destValue, destPath, startValue, startPath})
  if (destPath.length === 0) {
    return 'U'.repeat(startPath.length)
  }
  if (startPath.length === 0) {
    return destPath.join('');
  }
  const n = Math.min(destPath.length, startPath.length);
  let i = 0;
  while (i < n && destPath[i] == startPath[i]) {
    i++;
  }
  return 'U'.repeat(startPath.length - i) + destPath.slice(i,destPath.length).join('');
};

