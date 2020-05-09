/**
 * @param {string} s
 * @return {number}
 */
var maxScore = function(s) {
  const n = s.length;
  const zeros = Array(n+1).fill(0);
  const ones = Array(n+1).fill(0);
  for (let i = 1; i <= n; i++) {
    zeros[i] = zeros[i - 1] + ((s[i-1] === '0') ? 1 : 0);
  }
  for (let i = n - 1; i >= 0; i--) {
    ones[i] = ones[i+1] + ((s[i] === '1') ? 1 : 0);
  }
  // console.log({zeros, ones});
  let res = 0;
  for (let i = 1; i < n; i++) {
    res = Math.max(res, zeros[i] + ones[i]);
  }
  return res;
};