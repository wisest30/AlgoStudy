/**
 * @param {string[]} words
 * @return {string}
 */
var firstPalindrome = function(words) {
  for (const w of words) {
    const n = w.length;
    let lo = 0, hi = n - 1, palin = true;
    while (lo < hi) {
      if (w[lo] !== w[hi]) {
        palin = false;
        break;
      }
      lo++;
      hi--;
    }
    if (palin) {
      return w;
    }
  }
  return '';
};
