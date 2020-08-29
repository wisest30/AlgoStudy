/**
 * @param {number} n
 * @return {number}
 */
var minOperations = function(n) {
  let res = 0;
  for (let i = n -1; i > 0; i -= 2) {
    res += i;
  }
  return res;
};