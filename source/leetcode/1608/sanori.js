/**
 * @param {number[]} nums
 * @return {number}
 */
var specialArray = function(nums) {
  const n = nums.length;
  if (n < 1) {
    return -1;
  }
  for (let i = 1; i <= n; i++) {
    let cnt = 0;
    for (let j = 0; j < n; j++) {
      if (nums[j] >= i) {
        cnt++;
      }
    }
    if (i === cnt) {
      return cnt;
    }
  }
  return -1;
};