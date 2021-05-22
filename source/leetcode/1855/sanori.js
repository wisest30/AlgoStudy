/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
 var maxDistance = function(nums1, nums2) {
  const n1 = nums1.length;
  const n2 = nums2.length;
  let res = 0;
  for(let j = 0; j < n2; j++) {
    const target = nums2[j];
    // if (nums1[j] >= target) continue;
    let lo = 0, hi = Math.min(n1, j+1);
    while (lo < hi) {
      const mi = (lo + hi) >> 1;
      const val = nums1[mi];
      if (val > target) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    if (hi < n1 && nums1[hi] <= target) {
      res = Math.max(res, j - hi);
    }
  }
  return res;
};
