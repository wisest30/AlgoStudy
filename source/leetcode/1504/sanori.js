/**
 * @param {number[][]} mat
 * @return {number}
 */
var numSubmat = function(mat) {
  const m = mat.length;
  if (m < 1) {
    return 0;
  }
  const n = mat[0].length;
  const rowStruct = Array(m);
  for (let i = 0; i < m; i++) {
    rowStruct[i] = mat[i].slice();
  }
  
  let res = 0;
  
  for (let r = m; r > 0; r--) {
    const colStruct = Array(r);
    for (let i = 0; i < r; i++) {
      colStruct[i] = rowStruct[i].slice();
    }
    for (let ir = 0; ir < r; ir++) {
      const curRow = colStruct[ir];
      let len = 0;
      for (let ic = 0; ic < n; ic++) {
        len = (curRow[ic] == 0) ? 0 : len + 1;
        res += len;
      }
    }
    
    for (let i = 0; i < r - 1; i++) {
      for (let j = 0; j < n; j++) {
        rowStruct[i][j] = rowStruct[i][j] * rowStruct[i+1][j];
      }
    }
    delete rowStruct[r-1];
  }
  return res;
};