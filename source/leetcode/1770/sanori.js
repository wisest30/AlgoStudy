/**
 * @param {number[]} nums
 * @param {number[]} multipliers
 * @return {number}
 */
 var maximumScore = function(nums, multipliers) {
  const n = nums.length;
  const m = multipliers.length;
  const memo = {};
  const traverse = (l = 0, i = 0) => {
    if (i >= m) {
      return 0;
    }
    const idx = `${l},${i}`;
    if (memo[idx] === undefined) {
      const takeLeft = traverse(l+1, i+1) + nums[l] * multipliers[i];
      const takeRight = traverse(l, i+1) + nums[n - i + l - 1] * multipliers[i];
      memo[idx] = Math.max(takeLeft, takeRight);
    }
    return memo[idx];
  };
  const res = traverse();
  return res;
};
