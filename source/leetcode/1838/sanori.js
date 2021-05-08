/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
 var maxFrequency = function(nums, k) {
  const n = nums.length;
  nums.sort((a,b) => a - b);

  // console.log({n, nums});
  let res = 0, curSum = 0, lo = 0;
  for (let i = 1; i < n; i++) {
    curSum += (nums[i] - nums[i-1]) * (i - lo);
    while (curSum > k) {
      curSum -= nums[i] - nums[lo];
      lo++;
    }
    // console.log({i, lo, curSum, res});
    res = Math.max(res, i - lo);
  }
  res = Math.max(res, n - 1 - lo);

  return res + 1;
};
