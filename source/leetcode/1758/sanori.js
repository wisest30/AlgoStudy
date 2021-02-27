/**
 * @param {string} s
 * @return {number}
 */
var minOperations = function(s) {
  const n = s.length;
  let o0 = 0, e0 = 0;
  for (let i = 0; i < n; i++) {
    if (s[i] === '0') {
      if (i % 2 === 0) {
        e0++;
      } else {
        o0++;
      }
    }
  }
  const o1 = Math.floor(n/2) - o0;
  const e1 = Math.ceil(n/2) - e0;
  // console.log({e0, e1, o0, o1});
  return Math.min(e0 + o1, e1 + o0);
};
