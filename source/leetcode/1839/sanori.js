/**
 * @param {string} word
 * @return {number}
 */
 var longestBeautifulSubstring = function(word) {
  const n = word.length;
  const vowels = 'aeiou';

  let res = 0, curChar = -1, starts = -1;
  for (let i = 0; i < n; i++) {
    if (curChar < 0) {
      if (word[i] === vowels[0]) {
        curChar = 0;
        starts = i;
      }
    } else if (word[i] !== vowels[curChar]) {
      if (curChar < 4 && word[i] === vowels[curChar+1]) {
        curChar++;
      } else {
        if (curChar === 4) {
          res = Math.max(res, i - starts);
        }
        if (word[i] === 'a') {
          curChar = 0;
          starts = i;
        } else {
          curChar = -1;
        }
      }
    }
  }
  if (curChar === 4) {
    res = Math.max(res, n - starts);
  }
  return res;
};
