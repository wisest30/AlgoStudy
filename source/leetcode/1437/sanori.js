/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var kLengthApart = function(nums, k) {
  const n = nums.length;
  let start = 0;
  for (;start < n && nums[start] === 0; start++);
  
  let dist = 0;
  for (let i = start + 1; i < n; i++) {
    if(nums[i] === 1) {
      if (dist < k) {
        return false;
      }
      dist = 0;
    } else {
      dist++;
    }
  }
  return true;
};
