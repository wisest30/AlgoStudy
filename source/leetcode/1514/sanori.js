/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} succProb
 * @param {number} start
 * @param {number} end
 * @return {number}
 */
var maxProbability = function(n, edges, succProb, start, end) {
  const graph = Array(n).fill(null).map(() => []);
  const ne = edges.length;
  for (let i = 0; i < ne; i++) {
    const [u, v] = edges[i];
    const p = succProb[i];
    graph[u].push([v, p]);
    graph[v].push([u, p]);
  }

  const seen = Array(n).fill(0);
  seen[start] = 1;
  const q = [[start, 1]];
  while (q.length > 0) {
    const [u, p] = q.shift();
    for (const [v, p2] of graph[u]) {
      const np = p * p2;
      if (seen[v] < np) {
        q.push([v, np]);
        seen[v] = np;
      }
    }
  }
  return seen[end];
};