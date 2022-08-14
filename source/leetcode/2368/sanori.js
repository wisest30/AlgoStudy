/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} restricted
 * @return {number}
 */
 var reachableNodes = function(n, edges, restricted) {
  const graph = Array(n).fill(null).map(() => []);
  const rSet = new Set(restricted);
  for (const [u, v] of edges) {
    if (rSet.has(u) || rSet.has(v)) continue;
    graph[u].push(v);
    graph[v].push(u);
  }
  let res = 0;
  const visited = new Set();
  const traverse = (u, parent=-1) => {
    if (visited.has(u)) return;
    visited.add(u);
    res++;
    for (const v of graph[u]) {
      traverse(v, u);
    }
  };
  traverse(0);
  return res;
};
