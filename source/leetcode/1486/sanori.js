/**
 * @param {number} n
 * @param {number} start
 * @return {number}
 */
var xorOperation = function(n, start) {
  let res = 0;
  for (let i = 0; i < n; i++) {
    const e = start + 2 * i;
    res ^= e;
  }
  return res;
};