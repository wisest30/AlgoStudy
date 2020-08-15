/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxSum = function(nums1, nums2) {
  const mod = 1e9 + 7;
  const n1 = nums1.length;
  const n2 = nums2.length;
  let sum1 = 0, sum2 = 0;
  let p1 = 0, p2 = 0;
  while (p1 < n1 && p2 < n2) {
    if (nums1[p1] > nums2[p2]) {
      sum2 += nums2[p2++];
    } else if (nums1[p1] < nums2[p2]) {
      sum1 += nums1[p1++];
    } else { // nums1[p1] == nums2[p2]
      const max = Math.max(sum1, sum2);
      sum1 = max + nums1[p1];
      sum2 = max + nums1[p1];
      p1++;
      p2++;
    }
  }
  while (p1 < n1) {
    sum1 += nums1[p1++];
  }
  while (p2 < n2) {
    sum2 += nums2[p2++];
  }
  return (Math.max(sum1, sum2)) % mod;
};