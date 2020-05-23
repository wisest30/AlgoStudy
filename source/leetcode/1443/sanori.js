/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {boolean[]} hasApple
 * @return {number}
 */
var minTime = function(n, edges, hasApple) {
  const childs = Array(n).fill(null).map(() => []);
  for (const [u, v] of edges) {
    childs[u].push(v);
  }
  
  const traverse = (u) => {
    if (childs[u].length === 0) {
      return (hasApple[u]) ? 2 : 0;
    }
    let res = 0;
    for (const v of childs[u]) {
      const sub = traverse(v);
      res += sub;
    }
    if (res > 0 || hasApple[u]) {
      res += 2;
    }
    return res;
  }
  const res = traverse(0);
  return (res > 0) ? res - 2 : res;
};