/**
 * @param {number[][]} edges
 * @return {number}
 */
 var findCenter = function(edges) {
  const n = edges.length;
  const deg = {};
  for (const [u, v] of edges) {
    deg[u] = deg[u] + 1 || 1;
    deg[v] = deg[v] + 1 || 1;
  }
  for (let key in deg) {
    if (deg[key] === n) {
      return key;
    }
  }
};
