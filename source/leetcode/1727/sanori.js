/**
 * @param {number[][]} matrix
 * @return {number}
 */
var largestSubmatrix = function(matrix) {
  const m = matrix.length;
  if (m < 1) {
    return 0;
  }
  const n = matrix[0].length;

  // rewrite
  for (let c = 0; c < n; c++) {
    for (let r = 1; r < m; r++) {
      if (matrix[r][c] === 1) {
        matrix[r][c] = matrix[r-1][c] + 1;
      }
    }
  }

  let res = 0;
  for (let r = 0; r < m; r++) {
    matrix[r].sort((a, b) => b - a);
    for (let c = 0; c < n; c++) {
      res = Math.max(res, matrix[r][c] * (c+1));
    }
  }

  return res;
};
