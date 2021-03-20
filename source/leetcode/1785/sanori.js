/**
 * @param {number[]} nums
 * @param {number} limit
 * @param {number} goal
 * @return {number}
 */
 var minElements = function(nums, limit, goal) {
  const sum = nums.reduce((a,b) => a + b, 0);
  const diff = Math.abs(sum - goal);
  return Math.ceil(diff/limit);
};
