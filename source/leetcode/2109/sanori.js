/**
 * @param {string} s
 * @param {number[]} spaces
 * @return {string}
 */
var addSpaces = function(s, spaces) {
  const n = s.length;
  const resArr = [];
  spaces.sort((a, b) => b - a);
  let last = 0;
  while (spaces.length > 0) {
    const p = spaces.pop();
    resArr.push(s.slice(last, p));
    resArr.push(' ');
    last = p;
  }
  resArr.push(s.slice(last, n));
  return resArr.join('');
};
