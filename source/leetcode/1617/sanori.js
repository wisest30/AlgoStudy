/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var countSubgraphsForEachDiameter = function(n, edges) {
  const en = edges.length;
  const graph = Array(n).fill(null).map(() => new Set());

  for (const [u, v] of edges) {
    graph[u-1].add(v-1);
    graph[v-1].add(u-1);
  }

  const dist = (u, nodes, curDist = 0, parent = -1, visited = new Set()) => {
    let res = curDist;
    if (!nodes.has(u)) {
      return [0, 0];
    }
    visited.add(u);
    for (const v of graph[u]) {
      if (v !== parent && nodes.has(v)) {
        res = Math.max(res, dist(v, nodes, curDist + 1, u, visited)[0]);
      }
    }
    return [res, visited.size];
  };

  const res = Array(n-1).fill(0);
  const traverse = (i = 0, nodes = new Set()) => {
    if (i < n) {
      nodes.add(i);
      traverse(i+1, nodes);
      nodes.delete(i);
      traverse(i+1, nodes);
    } else if (nodes.size > 1) {
      let maxDist = -1;
      for (const i of nodes) {
        const [md, tr] = dist(i, nodes);
        if (tr < nodes.size) {
          return;
        }
        maxDist = Math.max(maxDist, md);
      }
      if (maxDist > 0) {
        res[maxDist-1]++;
      }
    }
  };

  traverse();
  return res;
};
