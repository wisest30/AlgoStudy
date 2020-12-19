/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxOperations = function(nums, k) {
  const freq = nums.reduce((acc, cur) => {
    acc[cur] = acc[cur] + 1 || 1;
    return acc;
  }, {});

  let res = 0;
  if (k % 2 === 0) {
    const c = Math.floor((freq[k/2]||0) / 2);
    res += c;
    // freq[k/2] -= c * 2;
  }

  for (const i in freq) {
    if (i >= k / 2) break;
    const t = Math.min(freq[i] || 0, freq[k-i] || 0);
    res += t;
  }
  return res;
};
