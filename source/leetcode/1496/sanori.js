var isPathCrossing = function(path) {
  const dir = {
    N: [0, 1],
    S: [0, -1],
    E: [1, 0],
    W: [-1, 0]
  };
  const n = path.length;
  let x = 0, y = 0;
  const locs = new Set(['0,0']);
  for (let i = 0; i < n; i++) {
    const [dx, dy] = dir[path[i]];
    x += dx;
    y += dy;
    const idx = `${x},${y}`;
    if (locs.has(idx)) {
      return true;
    }
    locs.add(idx);
  }
  return false;
};