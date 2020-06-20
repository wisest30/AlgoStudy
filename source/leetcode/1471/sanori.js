/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getStrongest = function(arr, k) {
  const n = arr.length;
  const aSorted = arr.slice().sort((a, b) => a - b);
  const med = (n % 2 === 1) ? aSorted[(n-1)/2] : aSorted[n/2-1];
  const resArr = arr.map(x => [x, Math.abs(x - med)]);
  resArr.sort((a, b) => (a[1] !== b[1]) ? b[1] - a[1] : b[0] - a[0]);
  return resArr.slice(0, k).map(x => x[0]);
};
