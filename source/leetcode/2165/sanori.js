/**
 * @param {number} num
 * @return {number}
 */
var smallestNumber = function (num) {
  if (-10 < num && num < 10) return num;
  if (num < 0) {
    const arr = (-num).toString().split('').map(Number).sort((a, b) => a - b);
    let res = arr.pop();
    while (arr.length > 0) {
      res = res * 10 + arr.pop();
    }
    return -res;
  }
  const arr = num.toString().split('').map(Number).sort((a, b) => b - a);
  let numZeros = 0;
  while (arr[arr.length - 1] === 0) {
    numZeros++;
    arr.pop();
  }
  let res = arr.pop();
  while (numZeros > 0) {
    res *= 10;
    numZeros--;
  }
  while (arr.length > 0) {
    res = res * 10 + arr.pop();
  }
  return res;
};
