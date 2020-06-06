/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxDotProduct = function(nums1, nums2) {
  const n1 = nums1.length;
  const n2 = nums2.length;
  const memo = {};
  const dp = (i, j) => {
    if (i < 0 || j < 0) {
      return -Infinity;
    }
    const idx = `${i},${j}`;
    if (memo[idx] === undefined) {
      const res = Math.max(dp(i-1,  j), dp(i, j-1),
        Math.max(0, dp(i-1, j-1)) + nums1[i] * nums2[j]);
      memo[idx] = res;
    }
    return memo[idx];
  }
  const res = dp(n1-1, n2-1);
  return res;
};