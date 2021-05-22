/**
 * @param {string} colors
 * @param {number[][]} edges
 * @return {number}
 */
 var largestPathValue = function(colors, edges) {
  const n = colors.length;
  const aCode = 'a'.charCodeAt(0);
  const graph = Array(n).fill(null).map(() => []);
  const inDeg = Array(n).fill(0);

  for (const [u, v] of edges) {
    if (u === v) return -1;
    graph[u].push(v);
    inDeg[v]++;
  }

  const memo = Array(n).fill(null).map(() => Array(26).fill(0));
  const visited = Array(n).fill(false);
  const q = [];
  for (let i = 0; i < n; i++) {
    if (inDeg[i] > 0) continue;
    q.push(i);
    memo[i][colors.charCodeAt(i) - aCode] = 1;
    visited[i] = true;
  }

  let res = -1, seen = 0;
  while (q.length > 0) {
    const u = q.shift();
    res = Math.max(res, Math.max(...memo[u]));
    seen++;
    for (const v of graph[u]) {
      const c = colors.charCodeAt(v) - aCode;
      for (let i = 0; i < 26; i++) {
        memo[v][i] = Math.max(memo[v][i], memo[u][i] + ((i === c) ? 1 : 0));
      }
      if (--inDeg[v] === 0) {
        q.push(v);
      }
    }
  }

  return (seen < n) ? -1 : res;
};
