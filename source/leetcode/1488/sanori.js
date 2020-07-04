/**
 * @param {number[]} rains
 * @return {number[]}
 */
var avoidFlood = function(rains) {
  const n = rains.length;
  const res = Array(n).fill(-1);
  const zeros = [];
  const minLower = (lb) => {
    let lo = 0, hi = zeros.length;
    while (lo < hi) {
      const mid = Math.floor((lo + hi) / 2);
      const v = zeros[mid];
      if (v < lb) {
        lo = mid + 1;
      } else if (v > lb) {
        hi = mid;
      } else {
        lo = hi = mid;
      }
    }
    // console.log({lb, lo, hi, v: zeros[hi], zeros});
    if (hi >= zeros.length) {
      return -1;
    }
    const res = zeros.splice(hi, 1);
    return res;
  };
  
  const lastRain = {};
  for (let i = 0; i < n; i++) {
    const l = rains[i];
    if (l === 0) {
      res[i] = 1;
      zeros.push(i);
    } else {
      if (lastRain[l] !== undefined) {
        const idx = minLower(lastRain[l]);
        // console.log({idx, i, l});
        if (idx < 0) {
          return [];
        }
        res[idx] = l;
      }
      lastRain[l] = i;
    }
  }
  return res;
};