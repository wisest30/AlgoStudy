const mod = 1e9 + 7;
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minAbsoluteSumDiff = function(nums1, nums2) {
  const n = nums1.length;
  const diffs = [];
  let sum = 0;
  for (let i = 0; i < n; i++) {
    const diff = Math.abs(nums1[i] - nums2[i]);
    sum = (sum + diff) % mod;
    diffs[i] = [diff, nums2[i], i];
  }

  diffs.sort((a, b) => b[0] - a[0]);
  nums1.sort((a, b) => a - b);
  const search = (x) => {
    let lo = 0, hi = n;
    while (lo < hi) {
      const mi = Math.floor((lo + hi) / 2);
      if (nums1[mi] < x) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    return hi;
  };

  let max = 0;
  for (let i = 0; i < n; i++) {
    const [diff, n2, idx] = diffs[i];
    if (diff === 0) break;
    const i1 = search(n2);
    let nDiff;
    if (i1 === n) {
      nDiff = Math.abs(nums1[i1-1] - n2);
    } else if (i1 === 0) {
      nDiff = Math.abs(nums1[i1] - n2);
    } else {
      nDiff = Math.min(Math.abs(nums1[i1-1] - n2), Math.abs(nums1[i1] - n2));
    }
    max = Math.max(max, diff - nDiff);
  }
  return (sum - max + mod) % mod;
};
