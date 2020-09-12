/**
 * @param {number[]} arr
 * @param {number} m
 * @param {number} k
 * @return {boolean}
 */
var containsPattern = function(arr, m, k) {
  const n = arr.length;
  let cnt = 0;
  for (let i = 0; i < n; i++) {
    if (arr[i] !== arr[i+m]) {
      cnt = 0;
    } else {
      cnt++;
      if (cnt === m * (k-1)) {
        return true;
      }
    }
  }
  return false;
};