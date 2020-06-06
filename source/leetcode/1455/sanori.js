/**
 * @param {string} sentence
 * @param {string} searchWord
 * @return {number}
 */
var isPrefixOfWord = function(sentence, searchWord) {
  const senArr = sentence.split(' ');
  const n = senArr.length;
  for (let i = 0; i < n; i++) {
    const sen = senArr[i];
    if (sen.startsWith(searchWord)) {
      return i + 1;
    }
  }
  return -1;
};