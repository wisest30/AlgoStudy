/**
 * @param {number[]} nums
 * @param {number[]} l
 * @param {number[]} r
 * @return {boolean[]}
 */
var checkArithmeticSubarrays = function(nums, l, r) {
  const n = nums.length;
  const m = l.length;

  const res = [];
  for (let i = 0; i < m; i++) {
    const sub = nums.slice(l[i], r[i]+1);
    sub.sort((a, b) => a - b);
    if (sub.length < 2) {
      res.push(false);
      continue;
    }
    let ans = true;
    const diff = sub[1] - sub[0];
    for (let i = 2; i < sub.length; i++) {
      if (sub[i] - sub[i-1] !== diff) {
        ans = false;
        break;
      }
    }
    res.push(ans);
  }
  return res;
};
