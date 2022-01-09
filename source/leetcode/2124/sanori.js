/**
 * @param {string} s
 * @return {boolean}
 */
 var checkString = function(s) {
  const n = s.length;
  for (let i = 0, bAppear = false; i < n; i++) {
    if (s[i] === 'b') {
      bAppear = true;
    } else if (s[i] === 'a') {
      if (bAppear) {
        return false;
      }
    }
  }
  return true;
};
