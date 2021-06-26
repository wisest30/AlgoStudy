/**
 * @param {string[]} words
 * @return {boolean}
 */
 var makeEqual = function(words) {
  const n = words.length;
  const aCode = 'a'.charCodeAt(0);
  const counts = Array(26).fill(0);
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < words[i].length; j++) {
      const idx = words[i].charCodeAt(j) - aCode;
      counts[idx]++;
    }
  }
  for (let i = 0; i < 26; i++) {
    if (counts[i] % n !== 0) {
      return false;
    }
  }
  return true;
};
