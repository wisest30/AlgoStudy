/**
 * @param {string} s
 * @return {string}
 */
var modifyString = function(s) {
  const n = s.length;
  const resArr = [];
  for (let i = 0; i < n; i++) {
    if (s[i] === '?') {
      if (resArr[i-1] !== 'a' && s[i+1] !== 'a') {
        resArr.push('a');
      } else if (resArr[i-1] !== 'b' && s[i+1] !== 'b') {
        resArr.push('b');
      } else {
        resArr.push('c');
      }
    } else {
      resArr.push(s[i]);
    }
  }
  return resArr.join('');
};