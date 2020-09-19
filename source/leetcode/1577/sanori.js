/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var numTriplets = function(nums1, nums2) {
  const n1 = nums1.length;
  const n2 = nums2.length;
  const sqr1 = nums1
    .map(x => x * x)
    .reduce((acc, cur) => {
      acc[cur] = acc[cur] + 1 || 1;
      return acc;
    }, {});
  const sqr2 = nums2
    .map(x => x * x)
    .reduce((acc, cur) => {
      acc[cur] = acc[cur] + 1 || 1;
      return acc;
    }, {});
  
  let res = 0;
  for (let i = 0; i < n1 - 1; i++) {
    for(let j = i + 1; j < n1; j++) {
      res += sqr2[nums1[i] * nums1[j]] || 0;
    }
  }
  
  for (let i = 0; i < n2 - 1; i++) {
    for(let j = i + 1; j < n2; j++) {
      res += sqr1[nums2[i] * nums2[j]] || 0;
    }
  }
  return res;
};