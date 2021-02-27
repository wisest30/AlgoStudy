/**
 * @param {string} s
 * @return {number}
 */
var countHomogenous = function(s) {
  const mod = 1e9 + 7;
  const n = s.length;

  let res = 0;
  let l = 0, r = 0;
  while (r < n) {
    if (s[l] === s[r]) {
      res = (res + r - l + 1) % mod;
      r++;
    } else {
      l = r;
    }
  }
  return res;
};
