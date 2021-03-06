/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
 var mergeAlternately = function(word1, word2) {
  const n1 = word1.length;
  const n2 = word2.length;
  const n = Math.max(n1, n2);
  const res = [];
  for (let i = 0; i < n; i++) {
    if (i < n1) {
      res.push(word1[i]);
    }
    if (i < n2) {
      res.push(word2[i]);
    }
  }
  return res.join('');
};
