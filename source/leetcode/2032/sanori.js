/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number[]} nums3
 * @return {number[]}
 */
 var twoOutOfThree = function(nums1, nums2, nums3) {
  const set1 = new Set(nums1);
  const set2 = new Set(nums2);
  const set3 = new Set(nums3);
  const cnt = {};
  for(const e of set1) {
    cnt[e] = cnt[e] + 1 || 1;
  }
  for(const e of set2) {
    cnt[e] = cnt[e] + 1 || 1;
  }
  for(const e of set3) {
    cnt[e] = cnt[e] + 1 || 1;
  }
  const res = [];
  for (const e in cnt) {
    if (cnt[e] >= 2) {
      res.push(e);
    }
  }
  return res;
};
