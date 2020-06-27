/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
  const prefix = nums.reduce((acc, cur) => {
    acc.push(acc[acc.length-1] + cur);
    return acc;
  }, [0])
  prefix.shift();
  return prefix;
};