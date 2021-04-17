/**
 * @param {number[]} nums
 * @return {number}
 */
 var countDifferentSubsequenceGCDs = function(nums) {
  const memo = {};
  const gcd = (a, b) => {
    if (a == 0) return b;
    if (a > b) return gcd(b, a);
    const idx = a * 1_000_000 + b;
    if (memo[idx] === undefined) {
      memo[idx] = gcd(b % a, a);
    }
    return memo[idx];
  }

  const max = Math.max(...nums);
  const s = new Set(nums);
  const factor = Array(max+1).fill(0);
  let res = 0;
  for (let i = 1; i <= max; i++) {
    let g = 0;
    for (let j = i; j <= max; j += i) {
      if (s.has(j)) {
        g = gcd(g, j);
        if (g === i) {
          break;
        }
      }
    }
    if (g === i) {
      res++;
    }
  }

  return res;
};
