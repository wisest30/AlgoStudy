/**
 * @param {string[]} words
 * @param {string} pref
 * @return {number}
 */
 var prefixCount = function(words, pref) {
  let res = 0;
  const m = pref.length;
  for (const w of words) {
    if (w.slice(0, m) === pref) {
      res++;
    }
  }
  return res;
};
