/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var findBall = function(grid) {
  const m = grid.length;
  if (m < 1) {
    return [];
  }
  const n = grid[0].length;
  const res = Array(n).fill(-1);
  for (let c = 0; c < n; c++) {
    let succ = true;
    let curC = c;
    for (let r = 0; r < m; r++) {
      if (grid[r][curC] === 1) {
        if (curC + 1 >= n || grid[r][curC+1] === -1) {
          succ = false;
          break;
        }
        curC++;
      } else { // grid[r][curC] === 0
        if (curC - 1 < 0 || grid[r][curC-1] === 1) {
          succ = false;
          break;
        }
        curC--;
      }
    }
    if (succ) {
      res[c] = curC;
    }
  }
  return res;
};