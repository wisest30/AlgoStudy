/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
  nums.sort((a,b) => b - a);
  return (nums[0] - 1) * (nums[1] - 1);
};