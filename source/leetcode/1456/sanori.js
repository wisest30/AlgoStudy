/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxVowels = function(s, k) {
  let curNV = 0;
  const n = s.length;
  for (let i = 0; i < k; i++) {
    if ("aeiou".indexOf(s[i]) >= 0) {
      curNV++;
    }
  }
  let max = curNV;
  for (let i = 0; i < n - k; i++) {
    const nch = s[i+k];
    const pch = s[i];
    if ('aeiou'.indexOf(nch) >= 0) {
      curNV++;
    }
    if ('aeiou'.indexOf(pch) >= 0) {
      curNV--;
    }
    max = Math.max(max, curNV);
  }
  return max;
};