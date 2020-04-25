/**
 * @param {string[]} words
 * @return {string[]}
 */
var stringMatching = function(words) {
  const n = words.length;
  words.sort((a,b) => a.length - b.length);
  const res = [];
  for (let i = 0; i < n - 1; i++) {
    for (let j = i + 1; j < n; j++) {
      if (words[j].indexOf(words[i]) >= 0) {
        res.push(words[i]);
        break;
      }
    }
  }
  return res;
};