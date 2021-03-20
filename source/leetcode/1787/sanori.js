/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
 var minChanges = function(nums, k) {
  const n = nums.length;
  const counts = Array(k).fill(null).map(() => Array(1024).fill(0));
  for (let i = 0; i < n; i++) {
    counts[i%k][nums[i]]++;
  }

  let dp = Array(1024).fill(-2000);
  dp[0] = 0;
  for (let i = 0; i < k; i++) {
    const maxDp = Math.max(...dp);
    const newDp = Array(1024).fill(maxDp);
    const curRow = counts[i];
    for(let j = 0; j < 1024; j++) {
      if (curRow[j] === 0) continue;
      for (let k = 0; k < 1024; k++) {
        newDp[k^j] = Math.max(newDp[k^j], curRow[j] + dp[k]);
      }
    }
    dp = newDp;
  }
  return nums.length - dp[0];
};
