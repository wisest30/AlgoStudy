/**
 * @param {number[]} nums
 * @return {number}
 */
var subArrayRanges = function (nums) {
  const n = nums.length;
  let res = 0;
  for (let i = 0; i < n - 1; i++) {
    let min = nums[i], max = nums[i];
    for (let j = i + 1; j < n; j++) {
      min = Math.min(min, nums[j]);
      max = Math.max(max, nums[j]);
      res += (max - min);
    }
  }
  return res;
};