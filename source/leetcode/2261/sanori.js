/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} p
 * @return {number}
 */
 var countDistinct = function(nums, k, p) {
  const n = nums.length;
  const subs = new Set();
  const q = [-1];
  for (let i = 0; i < n; i++) {
    const e = nums[i];
    if (e % p === 0) {
      q.push(i);
      while (q.length > k + 1) {
        q.shift();
      }
    }
    const start = q[0] + 1;
    for (let j = start; j < i+1; j++) {
      const subArr = nums.slice(j, i+1);
      subs.add(subArr.toString());
    }
  }
  return subs.size;
};
