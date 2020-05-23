/**
 * @param {number[]} target
 * @param {number} n
 * @return {string[]}
 */
var buildArray = function(target, n) {
  const m = target.length;
  let count = 1;
  let res = [];
  for (let i = 0; i < m; i++) {
    while (target[i] > count) {
      res.push('Push');
      res.push('Pop');
      count++;
    }
    res.push('Push');
    count++;
  }
  return res;
};