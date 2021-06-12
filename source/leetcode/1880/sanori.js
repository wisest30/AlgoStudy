/**
 * @param {string} firstWord
 * @param {string} secondWord
 * @param {string} targetWord
 * @return {boolean}
 */
 var isSumEqual = function(firstWord, secondWord, targetWord) {
  const aCode = 'a'.charCodeAt(0);
  const conv = (s) => {
    const n = s.length;
    let res = 0;
    for (let i = 0; i < n; i++) {
      res *= 10;
      res += (s.charCodeAt(i) - aCode);
    }
    return res; 
  }
  return conv(firstWord) + conv(secondWord) === conv(targetWord)
};
