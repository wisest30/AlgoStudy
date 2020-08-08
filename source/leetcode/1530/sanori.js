/**
 * @param {TreeNode} root
 * @param {number} distance
 * @return {number}
 */
var countPairs = function(root, distance) {
  const leafPaths = [];
  
  const dist = (p, q) => {
    const np = p.length;
    const nq = q.length;
    const n = Math.min(np, nq);
    for (let i = 0; i < n; i++) {
      if (p[i] !== q[i]) {
        return np + nq - 2 * i;
      }
    }
    return Math.max(np, nq) - n;
  }
  
  const countGood = (curPath) => {
    let res = 0; 
    for (const p of leafPaths) {
      if (dist(p, curPath) <= distance) {
        res++;
      }
    }
    return res;
  }
  
  let res = 0;
  const dfs = (u, path = []) => {
    if (u === null) return;  // wrong
    path.push(u);
    if (!u.left && !u.right) {  // leaf
      const curPath = path.slice();
      res += countGood(curPath);
      leafPaths.push(curPath);
    }
    
    if (u.left) {
      dfs(u.left, path);
    }
    if (u.right) {
      dfs(u.right, path);
    }
    path.pop();
  };
  dfs(root);
  return res;
};