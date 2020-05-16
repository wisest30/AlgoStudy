/**
 * @param {string[][]} paths
 * @return {string}
 */
var destCity = function(paths) {
  const nodes = {};
  for (const [u, v] of paths) {
    if (nodes[u] === undefined) {
      nodes[u] = [0, 1];
    } else {
      nodes[u][1]++;
    }
    if (nodes[v] === undefined) {
      nodes[v] = [1, 0];
    } else {
      nodes[v][0]++;
    }
  }
  for (const c in nodes) {
    if (nodes[c][1] === 0) {
      return c;
    }
  }
  return '';
};
