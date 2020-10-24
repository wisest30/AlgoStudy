/**
 * @param {number} n
 * @param {number[][]} roads
 * @return {number}
 */
var maximalNetworkRank = function(n, roads) {
  const graph = Array(n).fill(0);
  const con = new Set();
  for (const [u, v] of roads) {
    graph[u]++;
    graph[v]++;
    if (u < v) {
      con.add(`${u},${v}`);
    } else {
      con.add(`${v},${u}`);
    }
  }

  let res = 0;
  for (let u = 0; u < n - 1; u++) {
    for (let v = u + 1; v < n; v++) {
      const rank = graph[u] + graph[v]
        - (con.has(`${u},${v}`) ? 1 : 0);
      res = Math.max(res, rank);
    }
  }

  return res;
};
