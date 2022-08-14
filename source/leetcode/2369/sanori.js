/**
 * @param {number[]} nums
 * @return {boolean}
 */
 var validPartition = function(nums) {
  const n = nums.length;
  if (n < 2) {
    return false;
  }
  const dp = [false, nums[0] === nums[1]];
  dp[2] = (nums[0] === nums[1] && nums[1] === nums[2]) || (nums[0] + 1 === nums[1] && nums[1] + 1 === nums[2]);
  if (!dp[1] && !dp[2]) {
    return false;
  }
  for (let i = 3; i < n; i++) {
    if (nums[i-1] === nums[i] && dp[i-2]) {
      dp[i] = true;
      continue;
    }
    if (nums[i-2] === nums[i-1] && nums[i-1] === nums[i] && dp[i-3]) {
      dp[i] = true;
      continue;
    }
    dp[i] = (nums[i-2] + 1 === nums[i-1] && nums[i-1] + 1 === nums[i] && dp[i-3]);
  }
  // console.log({dp})
  return dp[n-1];
};
