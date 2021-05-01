/**
 * @param {string} sentence
 * @return {boolean}
 */
 var checkIfPangram = function(sentence) {
  const alpha = new Set();
  for (const ch of sentence) {
    alpha.add(ch);
  }
  return alpha.size === 26;
};
