/**
 * @param {number[][]} grid
 * @return {number}
 */
 var gridGame = function(grid) {
  const n = grid[0].length;
  if (n === 1) {
    return 0;
  }
  
  const upper = [];
  upper[n-1] = grid[0][n-1];
  for (let i = n - 2; i >= 0; --i) {
    upper[i] = upper[i+1] + grid[0][i];
  }
  
  const lower = [grid[1][0]];
  for (let i = 1; i < n; i++) {
    lower[i] = lower[i-1] + grid[1][i];
  }
  
  const sscore = [upper[1]];
  sscore[n-1] = lower[n-2];
  for (let i = 1; i < n - 1; i++) {
    sscore[i] = Math.max(upper[i+1], lower[i-1]);
  }
  
  return Math.min(...sscore);
};
