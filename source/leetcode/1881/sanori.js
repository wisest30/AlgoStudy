/**
 * @param {string} n
 * @param {number} x
 * @return {string}
 */
 var maxValue = function(n, x) {
  const m = n.length;
  const negative = (n[0] === '-');
  const nArr = n.split('');
  if (negative) {
    let i = 1;
    for (; i < m && n[i] <= x; i++);
    nArr.splice(i, 0, x);
  } else {
    let i = 0;
    for (; i < m && n[i] >= x; i++);
    nArr.splice(i, 0, x);
  }
  return nArr.join('');
};
