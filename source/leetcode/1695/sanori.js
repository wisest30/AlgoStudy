/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumUniqueSubarray = function(nums) {
  const n = nums.length;
  const seen = new Set();
  let res = 0;
  let lo = 0, hi = 0, sum = 0;
  while (hi < n) {
    const a = nums[hi];
    if (seen.has(a)) {
      do {
        seen.delete(nums[lo]);
        sum -= nums[lo];
        lo++;
      } while(nums[lo-1] !== a);
    }
    seen.add(a);
    sum += a;
    res = Math.max(res, sum);
    hi++;
  }
  return res;
};
