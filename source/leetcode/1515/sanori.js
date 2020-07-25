/**
 * @param {number[][]} positions
 * @return {number}
 */
var getMinDistSum = function(positions) {
  const n = positions.length;
  if (n < 2) {
    return 0;
  }
  const distSum = (x, y) => {
    let dist = 0;
    for (const [xi, yi] of positions) {
      const dx = x - xi;
      const dy = y - yi;
      dist += Math.sqrt(dx * dx + dy * dy);
    }
    return dist;
  };
  
  const dirs = [0, 1, 0, -1, 0];
  
  let cx = 0, cy = 0;
  let minX = Infinity, minY = Infinity, maxX = -Infinity, maxY = -Infinity;
  for (const [x, y] of positions) {
    cx += x;
    cy += y;
    minX = Math.min(minX, x);
    minY = Math.min(minY, y);
    maxX = Math.max(maxX, x);
    maxY = Math.max(maxY, y);
  }
  cx /= n;
  cy /= n;
  
  let minDist = distSum(cx, cy);
  let mDist = ((maxX - minX) + (maxY - minY)) / 2;
  
  while (mDist > 0.0000001) {
    let nx = cx, ny = cy;
    for (let i = 0; i < 4; i++) {
      const dx = dirs[i];
      const dy = dirs[i+1];
      const tx = cx + dx * mDist;
      const ty = cy + dy * mDist;
      const tDist = distSum(tx, ty);
      if (minDist > tDist) {
        nx = tx;
        ny = ty;
        minDist = tDist;
      }
    }
    cx = nx;
    cy = ny;
    mDist *= 0.95;
  }
  return minDist;
};