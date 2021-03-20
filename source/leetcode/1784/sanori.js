/**
 * @param {string} s
 * @return {boolean}
 */
 var checkOnesSegment = function(s) {
  const n = s.length;
  let zero = false;
  for (let i = 1; i < n; i++) {
    if (s[i] === '1') {
      if (zero) {
        return false;
      }
    } else {
      zero = true;
    }
  }
  return true;
};
