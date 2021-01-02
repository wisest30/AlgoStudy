/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxResult = function(nums, k) {
  const n = nums.length;
  const dp = [nums[0]];
  const q = [[nums[0],0]];
  for (let i = 1; i < n; i++) {
    dp[i] = q[0][0] + nums[i];
    while (q.length > 0 && q[0][1] < i - k + 1) {
      q.shift();
    }
    while (q.length > 0 && q[q.length-1][0] < dp[i]) {
      q.pop();
    }
    q.push([dp[i], i]);
  }
  return dp[n-1];
};
