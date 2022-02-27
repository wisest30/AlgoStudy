/**
 * @param {number} num
 * @return {number}
 */
var countEven = function (num) {
  let res = 0;
  for (let i = 1; i <= num; i++) {
    const sum = i.toString().split('').map(Number).reduce((a, b) => a + b, 0);
    if (sum % 2 === 0) {
      res++;
    }
  }
  return res;
};
