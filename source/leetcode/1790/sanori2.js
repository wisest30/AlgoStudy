/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var areAlmostEqual = function(s1, s2) {
  if (s1 == s2) {
    return true;
  }
  if (s1.length !== s2.length) {
    return false;
  }
  const n = s1.length;
  const diffs = [];
  for (let i = 0; i < n; i++) {
    if (s1[i] !== s2[i]) {
      if (diffs.length > 1) {
        return false;
      }
      diffs.push([s1[i], s2[i]]);
    }
  }
  return (diffs.length === 2 &&
          diffs[0][0] === diffs[1][1] &&
          diffs[0][1] === diffs[1][0]);
};
