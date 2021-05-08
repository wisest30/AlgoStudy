/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
 var sumBase = function(n, k) {
  const s = n.toString(k);
  return s.split('').map(Number).reduce((a, b) => a + b, 0);
};
