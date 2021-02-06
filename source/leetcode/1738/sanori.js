/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var kthLargestValue = function(matrix, k) {
  const m = matrix.length;
  if (m < 1) {
    return;
  }

  const n = matrix[0].length;
  for (let c = 1; c < n; c++) {
    matrix[0][c] ^= matrix[0][c-1];
  }
  for (let r = 1; r < m; r++) {
    matrix[r][0] ^= matrix[r-1][0];
  }
  for (let r = 1; r < m; r++) {
    for (let c = 1; c < n; c++) {
      matrix[r][c] ^= (matrix[r-1][c] ^ matrix[r-1][c-1] ^ matrix[r][c-1]);
    }
  }

  const arr = [];
  for (let r = 0; r < m; r++) {
    for (let c = 0; c < n; c++) {
      arr.push(matrix[r][c]);
    }
  }
  arr.sort((a, b) => b - a);
  return arr[k-1];
};