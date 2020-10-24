/**
 * @param {string} s
 * @return {number}
 */
var maxDepth = function(s) {
  const n = s.length;
  let res = 0;
  for (let i = 0, d = 0; i < n; i++) {
    if (s[i] === '(') {
      res = Math.max(res, ++d);
    } else if (s[i] === ')') {
      d--;
    }
  }
  return res;
};
