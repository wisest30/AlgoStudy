/**
 * @param {number[][]} mat
 * @return {number}
 */
var numSpecial = function(mat) {
  const m = mat.length;
  if (m < 1) {
    return 0;
  }
  const n = mat[0].length;
  const sRows = [];
  for (let r = 0; r < m; r++) {
    let sum = 0, last = -1;
    for (let c = 0; c < n; c++) {
      if (mat[r][c] === 1) {
        sum++;
        last = c;
      }
    }
    if (sum === 1) {
      sRows.push([r, last]);
    }
  }
  
  let res = 0;
  for (const [r1,c] of sRows) {
    let special = true;
    for (let r = 0; r < m; r++) {
      if (r !== r1 && mat[r][c] === 1) {
        special = false;
        break;
      }
    }
    if (special) {
      res++;
    }
  }
  return res;
};