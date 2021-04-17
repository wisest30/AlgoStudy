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
  for (const a of s) {
    for (let i = 1; i * i <= a; i++) {
      if (a % i === 0) {
        const fact1 = i;
        const fact2 = a / i;
        factor[fact1] = gcd(factor[fact1], a);
        factor[fact2] = gcd(factor[fact2], a);
      }
    }
  }

  let res = 0;
  for (let i = 1; i <= max; i++) {
    if (factor[i] === i) {
      res++;
    }
  }

  return res;
};