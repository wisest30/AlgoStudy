/**
 * @param {number[]} nums
 * @param {number} goal
 * @return {number}
 */
var minAbsDifference = function(nums, goal) {
  const n = nums.length;
  const h = Math.floor(n/2);
  const genSums = (lo, hi, cur = 0, acc = []) => {
    if (lo === hi) {
      acc.push(cur);
      acc.push(cur + nums[lo]);
    } else {
      genSums(lo + 1, hi, cur, acc);
      genSums(lo + 1, hi, cur + nums[lo], acc);
    }
    return acc;
  };

  const first = new Set(genSums(0, h-1));
  const second = Array.from(new Set(genSums(h, n-1))).sort((a,b) => a - b);
  let res = Math.abs(goal);

  const m = second.length;
  for (const a of first) {
    const target = goal - a;
    let lo = 0, hi = m-1;
    while (lo < hi) {
      const mid = Math.floor((lo + hi) / 2);
      if (second[mid] < target) {
        lo = mid + 1;
      } else if (second[mid] > target) {
        hi = mid;
      } else {
        res = 0;
        lo = mid;
        hi = mid;
        break;
      }
    }
    res = Math.min(res, Math.abs(goal - a - second[hi]));
    if (hi > 0) {
      res = Math.min(res, Math.abs(goal - a - second[hi-1]));
    }
    if (res === 0) break;
  }
  return res;
};
