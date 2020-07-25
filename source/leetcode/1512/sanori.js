/**
 * @param {number[]} nums
 * @return {number}
 */
var numIdenticalPairs = function(nums) {
  const freq = nums.reduce((acc, cur) => {
    acc[cur] = acc[cur] + 1 || 1;
    return acc;
  }, {});

  let res = 0;
  for (const a in freq) {
    const cnt = freq[a];
    res += (cnt) * (cnt - 1) / 2;
  }
  return res;
};