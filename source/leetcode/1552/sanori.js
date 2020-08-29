/**
 * @param {number[]} position
 * @param {number} m
 * @return {number}
 */
var maxDistance = function(position, m) {
  const n = position.length;
  const pos = position.sort((a,b) => a - b);
  // console.log({pos});
  const decide = (r) => {
    let cur = pos[0];
    let remain = m - 1;
    for (let i = 1; i < n; i++) {
      if (pos[i] - cur >= r) {
        remain--;
        cur = pos[i];
        if (remain <= 0) {
          return true;
        }
      }
    }
    return false;
  };
  /*
  let lo = Infinity;
  for (let i = 1; i < n; i++) {
    lo = Math.min(lo, pos[i] - pos[i-1]);
  }
  */
  let lo = 1;
  let hi = Math.floor((pos[n - 1] - pos[0]) / (m - 1));
  while (lo < hi) {
    const mid = Math.ceil((lo + hi) / 2);
    if (decide(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return hi;
};