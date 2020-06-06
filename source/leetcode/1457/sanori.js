/**
 * @param {TreeNode} root
 * @return {number}
 */
var pseudoPalindromicPaths  = function(root) {
  let res = 0;
  const counter = Array(9).fill(0);
  const isPal = () => {
    let numOdd = 0;
    for (let i = 0; i < 9; i++) {
      if (counter[i] % 2 === 1) {
        numOdd++;
        if (numOdd > 1) {
          return false;
        }
      }
    }
    return true;
  }
  const traverse = (u) => {
    if (!u) return;
    counter[u.val-1]++;
    if (!u.left && !u.right) {
      if (isPal()) {
        res++;
      }
    } else {
      traverse(u.left);
      traverse(u.right);
    }
    counter[u.val-1]--;
  };
  
  traverse(root);
  return res;
};