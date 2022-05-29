/**
 * @param {number[][]} stockPrices
 * @return {number}
 */
 var minimumLines = function(stockPrices) {
  const n = stockPrices.length;
  if (n < 3) {
    return n - 1;
  }
  stockPrices.sort((a, b) => a[0] - b[0]);
  const isSameSlope = (i, j) => BigInt(stockPrices[i+1][1] - stockPrices[i][1]) * BigInt(stockPrices[j+1][0] - stockPrices[j][0]) ===
      BigInt(stockPrices[j+1][1] - stockPrices[j][1]) * BigInt(stockPrices[i+1][0] - stockPrices[i][0]);
  
  let lo = 0, hi = 1, res = 1;
  while (hi < n - 1) {
    while (hi < n - 1 && isSameSlope(lo, hi)) {
      hi++;
    }
    if (hi < n - 1 && !isSameSlope(lo, hi)) {
      res++;
      lo = hi;
    }
    hi++;
  }
  return res;
};
