/**
 * @param {number[]} nums
 * @param {number} limit
 * @return {number}
 */
var longestSubarray = function(nums, limit) {
  const n = nums.length;
  let lo = 0, hi = 1;
  let min = nums[0], max = nums[0];
  let res = 0;
  while(hi <= n) {
    if (max - min > limit) {
      lo++;
      const sub = nums.slice(lo, hi);
      max = Math.max(...sub);
      min = Math.min(...sub);
    } else {
      res = Math.max(res, hi - lo);
      max = Math.max(max, nums[hi]);
      min = Math.min(min, nums[hi]);
      hi++;
    }
  }
  return res;
};