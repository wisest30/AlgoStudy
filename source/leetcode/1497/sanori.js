/**
 * @param {number[]} arr
 * @param {number} k
 * @return {boolean}
 */
var canArrange = function(arr, k) {
  const freq = arr.reduce((acc, cur) => {
    const idx = (cur % k + k) % k;
    acc[idx] = acc[idx] + 1 || 1;
    return acc;
  }, {});
  for (let i = 1; i < k / 2; i++) {
    const pair = k - i;
    if (freq[i] !== freq[pair]) {
      return false;
    }
  }
  if (k % 2 === 0 && freq[k/2] % 2 === 1) {
    return false;
  }
  return true;
};