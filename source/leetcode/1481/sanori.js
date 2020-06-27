/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var findLeastNumOfUniqueInts = function(arr, k) {
  const freq = arr.reduce((acc, cur) => {
    acc[cur] = acc[cur] + 1 || 1;
    return acc;
  }, {});
  const vals = Object.values(freq);
  vals.sort((a,b) => b - a);
  for (let r = k; r > 0; ) {
    if (vals[vals.length-1] <= r) {
      const v = vals.pop();
      r -= v;
    } else {
      vals[vals.length-1] -= r;
      r = 0;
    }
  }
  return vals.length;
};