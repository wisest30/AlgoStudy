const mod = 1e9 + 7;
/**
 * @param {number[]} packages
 * @param {number[][]} boxes
 * @return {number}
 */
var minWastedSpace = function(packages, boxes) {
  const n = packages.length;
  packages.sort((a,b) => a - b);
  const preSum = packages.reduce((acc, cur) => {
    acc.push(acc[acc.length-1] + cur);
    return acc;
  }, [0]);

  const upperBound = (target) => {
    let lo = 0, hi = n;
    while (lo < hi) {
      const mi = (lo + hi) >> 1;
      const val = packages[mi];
      if (val <= target) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    return lo;
  }

  let res = Infinity;
  for (const bs of boxes) {
    bs.sort((a, b) => b - a);
    if (bs[0] < packages[n-1]) continue;
    let wastes = bs[0] * n - preSum[n];
    let last = bs[0];
    for (let i = 1; i < bs.length; i++) {
      const b = bs[i];
      const j = upperBound(b);
      if (j <= 0) {
        break;
      }
      wastes -= (last - b) * j;
      last = b;
    }
    res = Math.min(res, wastes);
  }
  return (res === Infinity) ? -1 : res % mod;
};
