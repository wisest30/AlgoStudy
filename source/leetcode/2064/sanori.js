/**
 * @param {number} n
 * @param {number[]} quantities
 * @return {number}
 */
 var minimizedMaximum = function(n, quantities) {
  const m = quantities.length;
  const sum = quantities.reduce((a,b) => a+b, 0);
  const isFeasible = (k) => {
    let remain = n;
    for (let i = 0; i < m && remain >= 0; i++) {
      remain -= Math.ceil(quantities[i] / k);
    }
    return (remain >= 0);
  }
  let lo = Math.floor(sum/n), hi = Math.max(...quantities) + 1;
  while (lo < hi) {
    const mi = (lo + hi) >> 1;
    if (isFeasible(mi)) {
      hi = mi;
    } else {
      lo = mi + 1;
    }
  }
  return hi;
};
