const gcd = (a, b) => (b) ? gcd(b, a % b) : a;

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var replaceNonCoprimes = function(nums) {
  const n = nums.length;
  if (n < 1) return [];

  const res = [nums[0]];
  for (let i = 1; i < n; i++) {
    let cur = nums[i];
    let last = res[res.length-1];
    let g = gcd(last, cur);
    while(g > 1) {
      cur = cur * last / g;
      res.pop();
      if (res.length < 1) break;
      last = res[res.length-1];
      g = gcd(last, cur);
    }
    res.push(cur);
  }
  return res;
};
