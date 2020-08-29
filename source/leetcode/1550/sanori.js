/**
 * @param {number[]} arr
 * @return {boolean}
 */
var threeConsecutiveOdds = function(arr) {
  let count = 0;
  for (const a of arr) {
    if (a % 2 === 1) {
      count++;
      if (count >= 3) {
        return true;
      }
    } else {
      count = 0;
    }
  }
  return false;
};