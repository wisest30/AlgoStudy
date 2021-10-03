/**
 * @param {number[]} nums
 * @return {number}
 */
 var maximumDifference = function(nums) {
  const n = nums.length;
  let res = -1;
  for (let j = n - 1; j > 0; --j) {
    for (let i = 0; i < j; i++) {
      if (nums[j] > nums[i]) {
        res = Math.max(res, nums[j] - nums[i]);
      }
    }
  }
  return res;
};
