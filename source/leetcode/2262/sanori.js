const aCode = 'a'.charCodeAt(0);
/**
 * @param {string} s
 * @return {number}
 */
var appealSum = function(s) {
  const n = s.length;
  const last = Array(26);
  let res = 0;
  for (let i = 0; i < n; i++) {
    const idx = s.charCodeAt(i) - aCode;
    last[idx] = i;
    for (let j = 0; j < 26; j++) {
      if (last[j] !== undefined) {
        res += last[j] + 1;
      }
    }
  }
  return res;
};
