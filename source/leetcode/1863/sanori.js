/**
 * @param {number[]} nums
 * @return {number}
 */
 var subsetXORSum = function(nums) {
  const n = nums.length;
  const pow = 1 << n;
  let res = 0;
  for (let i = 0; i < pow; i++) {
    let sum = 0;
    for (let j = 0; j < n; j++) {
      if ((1 << j) & i) {
        sum ^= nums[j];
      }
    }
    res += sum;
  }
  return res;
};
