/**
 * @param {number} n
 * @param {number[][]} connections
 * @return {number}
 */
var minReorder = function(n, connections) {
  const uGraph = Array(n).fill(null).map(() => []);
  const dGraph = Array(n).fill(null).map(() => new Set());
  for (const [u, v] of connections) {
    uGraph[u].push(v);
    uGraph[v].push(u);
    dGraph[v].add(u);
  }
  let res = 0;
  const traverse = (u, parent) => {
    for (const v of uGraph[u]) {
      if (v !== parent) {
        if (!dGraph[u].has(v)) {
          res++;
        }
        traverse(v, u);
      }
    }
  }
  traverse(0, -1);
  return res;
};