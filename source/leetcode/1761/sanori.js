/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var minTrioDegree = function(n, edges) {
  const graph = Array(n).fill(null).map(() => []);
  const edgeSet = new Set();
  for (const [u, v] of edges) {
    graph[u-1].push(v-1);
    graph[v-1].push(u-1);
    edgeSet.add(`${u-1},${v-1}`);
    edgeSet.add(`${v-1},${u-1}`);
  }

  let res = Infinity;
  for (let i = 0; i < n; i++) {
    const degI = graph[i].length;
    const arr = graph[i];
    for (let j = 0; j < degI - 1; j++) {
      for (let k = j + 1; k < degI; k++) {
        const u = arr[j], v = arr[k];
        if (edgeSet.has(`${u},${v}`)) {
          const degU = graph[u].length;
          const degV = graph[v].length;
          res = Math.min(res, degI + degU + degV - 6);
        }
      }
    }
  }
  return (res === Infinity) ? -1 : res;
};
