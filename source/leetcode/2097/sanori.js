/**
 * @param {number[][]} pairs
 * @return {number[][]}
 */
var validArrangement = function(pairs) {
  const deg = {};
  const graph = {};
  for (const [u,v] of pairs) {
    if (deg[u] === undefined) {
      deg[u] = -1;
    } else {
      deg[u]--;
    }
    if (deg[v] === undefined) {
      deg[v] = 1;
    } else {
      deg[v]++;
    }
    if (graph[u] === undefined) {
      graph[u] = [v];
    } else {
      graph[u].push(v);
    }
  }

  let start = pairs[0][0];
  for (const u in deg) {
    if (deg[u] === -1) {
      start = Number(u);
      break;
    }
  }

  const s = [start], route = [];
  
  while (s.length > 0) {
    let top = s[s.length-1];
    while (graph[top] && graph[top].length > 0) {
      s.push(graph[top].pop());
      top = s[s.length-1];
    }
    route.push(s.pop());
  }
  
  const res = [];
  while (route.length > 1) {
    res.push([route[route.length-1], route[route.length-2]]);
    route.pop();
  }
  return res;
};

