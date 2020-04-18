/**
 * @param {number[]} nums
 * @return {number[]}
 */
var minSubsequence = function(nums) {
  const sum = nums.reduce((a,b) => a + b, 0);
  const thr = Math.floor(sum / 2);
  nums.sort((a,b) => b - a);
  const res = [];
  let resSum = 0;
  for (const x of nums) {
    resSum += x;
    res.push(x);
    if (resSum > thr) {
      break;
    }
  }
  return res;
};
