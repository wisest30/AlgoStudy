/**
 * @param {number[]} nums
 * @param {number} limit
 * @return {number}
 */
var minMoves = function(nums, limit) {
  const n = nums.length;
  const n2 = n / 2;
  const freq = {};
  for (let i = 0; i < n2; i++) {
    const ent = nums[i] + nums[n-i-1];
    freq[ent] = freq[ent] + 1 || 1;
  }

  const makeComp = (target) => {
    let res = 0;
    for (let i = 0; i < n2; i++) {
      if (nums[i] + nums[n-i-1] === target) continue;
      const a = target - nums[i];
      const b = target - nums[n-i-1];
      if ((a > limit || a < 1) &&
          (b > limit || b < 1)) {
        res += 2;
      } else {
        res++;
      }
    }
    // console.log({target, res});
    return res;
  };

  const freqArr = Object.entries(freq)
    .map(x => [Number(x[0]), x[1]]);
  freqArr.sort((a, b) => b[1] - a[1]);
  // console.log({freqArr});
  let res = n;
  for (const [ent, f] of freqArr) {
    if (n2 - f > res) {
      break;
    }
    res = Math.min(res, makeComp(ent));
  }
  return res;
};
