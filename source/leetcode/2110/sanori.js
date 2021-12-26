/**
 * @param {number[]} prices
 * @return {number}
 */
 var getDescentPeriods = function(prices) {
  const n = prices.length;
  let last = 0;
  let res = n;
  for (let i = 1; i < n; i++) {
    if (prices[i-1] !== prices[i] + 1) {
      const d = i - last;
      res += d * (d - 1) / 2;
      last = i;
    }
  }
  const d = n - last;
  res += d * (d - 1) / 2;
  return res;
};
