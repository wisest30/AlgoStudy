/**
 * @param {number[]} nums
 * @param {number} target
 * @param {number} start
 * @return {number}
 */
 var getMinDistance = function(nums, target, start) {
  const n = nums.length;
  for (let i = 0; i < n; i++) {
    if (start - i >= 0 && nums[start - i] === target) {
      return i;
    }
    if (start + i < n && nums[start + i] === target) {
      return i;
    }
  }
  return -i;
};
