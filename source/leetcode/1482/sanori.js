/**
 * @param {number[]} bloomDay
 * @param {number} m
 * @param {number} k
 * @return {number}
 */
var minDays = function(bloomDay, m, k) {
  const n = bloomDay.length;
  const isPossible = (c) => {
    let numB = 0;
    for(let i = 0, kinds = 0; i < n; i++) {
      if (bloomDay[i] <= c) {
        kinds++;
        if (kinds >= k) {
          numB++;
          kinds = 0;
        }
      } else {
        kinds = 0;
      }
      if (numB >= m) {
        return true;
      }
    }
    return (numB >= m);
  }
  
  const vals = Array.from(new Set(bloomDay));
  vals.sort((a,b) => a - b);
  const nv = vals.length;
  let lo = 0, hi = nv;
  while (lo < hi) {
    const mid = Math.floor((lo + hi) / 2);
    const mVal = vals[mid];
    const result = isPossible(mVal);
    if (result) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return (hi >= nv) ? -1 : vals[hi];
};