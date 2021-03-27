/**
 * @param {number[][]} edges
 * @return {number}
 */
 var findCenter = function(edges) {
  const deg = {};
  for (const [u, v] of edges) {
    deg[u] = deg[u] + 1 || 1;
    deg[v] = deg[v] + 1 || 1;
    if (deg[u] > 1) {
      return u;
    }
    if (deg[v] > 1) {
      return v;
    }
  }
};
