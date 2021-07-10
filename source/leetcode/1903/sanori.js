/**
 * @param {string} num
 * @return {string}
 */
 var largestOddNumber = function(num) {
  const n = num.length;
  for (let i = n - 1; i >= 0; i--) {
    if (Number(num[i]) % 2 === 1) {
      return num.slice(0, i+1);
    }
  }
  return '';
};
