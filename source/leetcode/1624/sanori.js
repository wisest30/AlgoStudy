/**
 * @param {string} s
 * @return {number}
 */
var maxLengthBetweenEqualCharacters = function(s) {
  const n = s.length;
  const first = {}, last = {};
  let maxDist = -1;
  for (let i = 0; i < n; i++) {
    const ch = s[i];
    if (first[ch] === undefined) {
      first[ch] = i;
    } else {
      last[ch] = i;
      maxDist = Math.max(maxDist, i - first[ch] - 1);
    }
  }

  return maxDist;
};
