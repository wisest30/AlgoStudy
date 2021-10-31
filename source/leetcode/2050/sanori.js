/**
 * @param {number} n
 * @param {number[][]} relations
 * @param {number[]} time
 * @return {number}
 */
 var minimumTime = function(n, relations, time) {
  const graph = Array(n).fill(null).map(() => []);
  const inDeg = Array(n).fill(0);
  for (const [u, v] of relations) {
    graph[u-1].push(v-1);
    inDeg[v-1]++;
  }

  const dist = time.slice();
  const q = [];
  for (let i = 0; i < n; i++) {
    if (inDeg[i] === 0) {
      q.push(i);
    }
  }
  while(q.length > 0) {
    const u = q.shift();
    for (const v of graph[u]) {
      dist[v] = Math.max(dist[v], dist[u] + time[v]);
      inDeg[v]--;
      if (inDeg[v] === 0) {
        q.push(v);
      }
    }
  }
  return Math.max(...dist);
};
