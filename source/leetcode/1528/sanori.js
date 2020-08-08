/**
 * @param {string} s
 * @param {number[]} indices
 * @return {string}
 */
var restoreString = function(s, indices) {
  const n = s.length;
  const resArr = [];
  for (let i = 0; i < n; i++) {
    resArr[indices[i]] = s[i];
  }
  return resArr.join('');
};