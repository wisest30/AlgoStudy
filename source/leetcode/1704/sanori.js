/**
 * @param {string} s
 * @return {boolean}
 */
var halvesAreAlike = function(s) {
  const n = s.length;
  const vSet = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
  let c0 = 0, c1 = 0;
  
  for (let i = 0; i < n/2; i++) {
    if (vSet.has(s[i])) {
      c0++;
    }
    if (vSet.has(s[n-i-1])) {
      c1++;
    }
  }
  return c0 === c1;
};