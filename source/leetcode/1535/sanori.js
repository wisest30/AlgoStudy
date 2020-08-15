/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var getWinner = function(arr, k) {
  const n = arr.length;
  if (n < 2) {
    return arr[0] || 0;
  }
  let wIdx = 0, won = 0;
  for (let i = 1; i < n && won < k; i++, won++) {
    if (arr[wIdx] < arr[i]) {
      wIdx = i;
      won = 0;
    }
  }
  return arr[wIdx];
};