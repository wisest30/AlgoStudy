/**
 * @param {number[][]} grid
 * @param {number} x
 * @return {number}
 */
 var minOperations = function(grid, x) {
  const m = grid.length;
  const n = grid[0].length;
  const remainder = grid[0][0] % x;
  const arr = [];
  for (let r = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      if (grid[r][c] % x !== remainder) {
        return -1;
      }
      arr.push((grid[r][c] - remainder) / x);
    }
  }
  arr.sort((a,b) => a - b);
  const median = arr[Math.floor(arr.length/2)];
  let res = 0;
  for (let i = 0; i < arr.length; i++) {
    res += Math.abs(median - arr[i]);
  }
  return res;
};