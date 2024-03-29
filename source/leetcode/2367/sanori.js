/**
 * @param {number[]} nums
 * @param {number} diff
 * @return {number}
 */
 var arithmeticTriplets = function(nums, diff) {
  const n = nums.length;  
  let res = 0;
  for (let i = 0; i < n - 2; i++) {
    for (let j = i + 1; j < n - 1; j++) {
      if (nums[j] - nums[i] !== diff) continue;
      for (let k = j + 1; k < n; k++) {
        if (nums[k] - nums[j] === diff) {
          res++;
        }
      }
    }
  }
  return res;
};
