/**
 * @param {number[]} nums
 * @return {number}
 */
var tupleSameProduct = function(nums) {
  const n = nums.length;
  const nSet = new Set(nums);
  nums.sort((a, b) => a - b);
  let res = 0;
  for (let i = 0; i < n - 3; i++) {
    for (let j = n - 1; j >= i + 2; --j) {
      const prod = nums[i] * nums[j];
      for (let k = i + 1; k < j; k++) {
        if (prod % nums[k] === 0 && prod > nums[k] * nums[k] &&
            nSet.has(prod / nums[k])) {
          res++;
        }
      }
    }
  }
  return 8 * res;
};
