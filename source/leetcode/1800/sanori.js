/**
 * @param {number[]} nums
 * @return {number}
 */
 var maxAscendingSum = function(nums) {
  const n = nums.length;
  if (n < 1) {
    return 0;
  }
  let sum = nums[0];
  let res = 0;
  for (let i = 1; i < n; i++) {
    if (nums[i-1] >= nums[i]) {
      res = Math.max(res, sum);
      sum = nums[i];
    } else {
      sum += nums[i];
    }
  }
  res = Math.max(res, sum);

  return res;
};
