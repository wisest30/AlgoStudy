/**
 * @param {number} num
 * @return {boolean}
 */
var isSameAfterReversals = function (num) {
  const reversed = parseInt(num.toString(10).split('').reverse().join(''), 10);
  const restored = parseInt(reversed.toString(10).split('').reverse().join(''), 10);
  return num == restored;
};