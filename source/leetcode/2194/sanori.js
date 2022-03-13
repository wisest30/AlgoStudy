/**
 * @param {string} s
 * @return {string[]}
 */
 var cellsInRange = function(s) {
  const aCode = 'A'.charCodeAt(0);
  const colFrom = s.charCodeAt(0) - aCode;
  const colTo = s.charCodeAt(3) - aCode;
  const rowFrom = Number(s[1]);
  const rowTo = Number(s[4]);
  const res = [];
  for (let c = colFrom; c <= colTo; c++) {
    for (let r = rowFrom; r <= rowTo; r++) {
      res.push(String.fromCharCode(aCode + c) + r.toString());
    }
  }
  return res;
};
