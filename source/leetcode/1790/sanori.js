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
  for (let i = 0; i < n-1; i++) {
    for (let j = i + 1; j < n; j++) {
      const newS2 = s2.split('');
      const tmp = newS2[j];
      newS2[j] = newS2[i];
      newS2[i] = tmp;
      if (s1 === newS2.join('')) {
        return true;
      }
    }
  }
  return false;
};
