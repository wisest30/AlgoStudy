/**
 * @param {string} num
 * @param {number} k
 * @return {string}
 */
var minInteger = function(num, k) {
  if (k <= 0) {
    return num;
  }
  const n = num.length;
  if (k >= n * (n-1) / 2) {
    return num.split('').sort().join('');
  }
  for (let i = 0; i < 10; i++) {
    const idx = num.indexOf(i);
    if (0 <= idx && idx <= k) {
      const newNum = num.slice(0, idx) + num.slice(idx+1, n);
      return num[idx] + minInteger(newNum, k - idx);
    }
  }
  return '';
};