/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number[][]}
 */
 var rotateGrid = function(grid, k) {
  const m = grid.length; 
  const n = grid[0].length;
  const res = Array(m).fill(null).map(() => Array(n).fill(1));
  let layer = Math.min(m, n) / 2 - 1;
  while (layer >= 0) {
    const mod = 2 * (m + n - 4 * layer - 2);
    const arr = [];
    for (let c = layer, r = layer; c < n - layer; c++) {
      arr.push(grid[r][c]);
    }
    for (let r = layer + 1, c = n - layer - 1; r < m - layer; r++) {
      arr.push(grid[r][c]);
    }
    for (let c = n - layer - 2, r = m - layer - 1; c >= layer; --c) {
      arr.push(grid[r][c]);
    }
    for (let r = m - layer - 2, c = layer; r > layer;--r) {
      arr.push(grid[r][c]);
    }
    
    let i = k;
    for (let c = layer, r = layer; c < n - layer; c++) {
      res[r][c] = arr[i++ % mod];
    }
    for (let r = layer + 1, c = n - layer - 1; r < m - layer; r++) {
      res[r][c] = arr[i++ % mod];
    }
    for (let c = n - layer - 2, r = m - layer - 1; c >= layer; --c) {
      res[r][c] = arr[i++ % mod];
    }
    for (let r = m - layer - 2, c = layer; r > layer; --r) {
      res[r][c] = arr[i++ % mod];
    }
    
    layer--;
  }
  return res;
};
