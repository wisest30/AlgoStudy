/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var maxNonOverlapping = function(nums, target) {
  const n = nums.length;
  const preSum = nums.reduce((acc, cur) => {
    acc.push(acc[acc.length-1] + cur);
    return acc;
  }, [0]);
  let res = 0;
  let lo = 0;
  for (let j = 1; j <= n; j++) {
    for (let i = lo; i < j; i++) {
      if (preSum[j] - preSum[i] === target) {
        lo = j;
        res++;
        break;
      }
    }
  }
  return res;
};