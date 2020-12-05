/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getSmallestString = function(n, k) {
  const resArr = [];
  while (n > 0) {
    const det = k - (n-1) * 26;
    if (det <= 0) {
      resArr.push(1);
      k--;
    } else {
      resArr.push(det);
      k -= det;
    }
    n--;
  }
  return resArr.map(x => String.fromCharCode(x + 96)).join('');
};
