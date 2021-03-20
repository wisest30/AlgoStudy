/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
 var countRestrictedPaths = function(n, edges) {
  const graph = Array(n).fill(null).map(() => []);
  for (const [u, v, w] of edges) {
    graph[u-1].push([v-1, w]);
    graph[v-1].push([u-1, w]);
  }
  const dtn = Array(n);
  dtn[n-1] = 0;
  const q = [[n-1, 0]];
  while (q.length > 0) {
    const [u, d] = q.shift();
    for (const [v, w] of graph[u]) {
      if (dtn[v] !== undefined && dtn[v] <= d + w) continue;
      q.push([v, d + w]);
      dtn[v] = d + w;
    }
  }
  const mod = 1e9 + 7;
  const kinds = Array(n);
  kinds[n-1] = 1;
  const visited = Array(n).fill(false);
  const traverse = (u) => {
    if (kinds[u] !== undefined) return kinds[u];
    let res = 0;
    for (const [v, w] of graph[u]) {
      if (dtn[v] < dtn[u]) {
        res = (res + traverse(v)) % mod;
      }
    }
    kinds[u] = res;
    return res;
  };
  const res = traverse(0);
  return res;
};
