/**
 * @param {number[]} digits
 * @return {number[]}
 */
var findEvenNumbers = function(digits) {
  const dArr = digits.sort((a,b) => b - a);
  const n = dArr.length;
  if (n < 1 || dArr[0] === 0) {
    return [];
  }
  const resSet = new Set();
  for (let i = 0; i < n; i++) {
    if (dArr[i] === 0) break;
    for (let j = 0; j < n; j++) {
      if (i === j) continue;
      for (let k = 0; k < n; k++) {
        if (k === i || k === j || ((dArr[k] % 2) === 1)) continue;
        resSet.add(dArr[i]*100 + dArr[j]*10 + dArr[k]);
      }
    }
  }
  const res = Array.from(resSet);
  res.sort((a,b) => a - b);
  return res;
};

