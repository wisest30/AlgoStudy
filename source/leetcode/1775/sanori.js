/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
 var minOperations = function(nums1, nums2) {
  const n1 = nums1.length;
  const n2 = nums2.length;
  if (n1*6 < n2 || n1 > n2*6) {
    return -1;
  }
  const freq1 = nums1.reduce((acc, cur) => {
    acc[cur] = acc[cur] + 1 || 1;
    return acc;
  }, {});
  const sum1 = nums1.reduce((a, b) => a + b, 0);
  const freq2 = nums2.reduce((acc, cur) => {
    acc[cur] = acc[cur] + 1 || 1;
    return acc;
  }, {});
  const sum2 = nums2.reduce((a, b) => a + b, 0);

  let diff = Math.abs(sum1 - sum2);
  if (diff === 0) {
    return 0;
  }
  const cap = Array(5).fill(0);
  if (sum1 > sum2) {
    for (let i = 6; i > 1; --i) {
      cap[i-1] = (freq1[i]|| 0) + (freq2[6-i+1] || 0);
    }
  } else {
    for (let i = 6; i > 1; --i) {
      cap[i-1] = (freq2[i] || 0) + (freq1[6-i+1] || 0);
    }
  }

  let res = 0;
  for (let d = 5; d > 0 && diff > 0; --d) {
    if (diff >= cap[d] * d) {
      diff -= cap[d] * d;
      res += cap[d];
      cap[d] = 0;
    } else {
      res += Math.ceil(diff / d);
      diff = 0;
      cap[d] -= Math.ceil(diff / d);
    }
  }
  return res;
};
