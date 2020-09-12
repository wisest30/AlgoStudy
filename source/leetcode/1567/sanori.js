/**
 * @param {number[]} nums
 * @return {number}
 */
var getMaxLen = function(nums) {
  let res = 0, pos= 0, neg = 0;
  for (const a of nums) {
    if (a > 0) {
      pos++;
      if (neg !== 0) {
        neg++;
      }
    } else if (a < 0) {
      const prePos = pos;
      pos = (neg === 0) ? 0 : neg+1;
      neg = prePos + 1;
    } else {
      pos = 0;
      neg = 0;
    }
    res = Math.max(res, pos);
  }
  return res;
};