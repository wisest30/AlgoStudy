/**
 * @param {number[]} nums
 * @return {number}
 */
 var arraySign = function(nums) {
  const prod = nums.reduce((acc, cur) => acc * cur, 1);
  return (prod > 0) ? 1 :(prod < 0 ? -1 : 0);
};
