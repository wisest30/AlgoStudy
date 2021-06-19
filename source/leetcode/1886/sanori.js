/**
 * @param {number[][]} mat
 * @param {number[][]} target
 * @return {boolean}
 */
 var findRotation = function(mat, target) {
  const n = mat.length;
  const rotate = () => {
    for (let r = 0; r < n -1; r++) {
      for (let c = r+1; c < n; c++) {
        const tmp = mat[r][c];
        mat[r][c] = mat[c][r];
        mat[c][r] = tmp;
      }
    }
    for (let r = 0; r < n; r++) {
      for (let c = 0; c < n/2; c++) {
        const tmp = mat[r][c];
        mat[r][c] = mat[r][n-c-1];
        mat[r][n-c-1] = tmp;
      }
    }
  };

  const isSame = () => {
    for (let r = 0; r < n; r++) {
      for (let c = 0; c < n; c++) {
        if (mat[r][c] !== target[r][c]) {
          return false;
        }
      }
    }
    return true;
  }

  if (isSame()) return true;
  for (let i = 0; i < 3; i++) {
    rotate();
    if (isSame())
      return true;
  }
  return false;
};