/**
 * @param {number[]} strength
 * @return {number}
 */
 var totalStrength = function(strength) {
  const mod = 1e9 + 7;
  const n = strength.length;
  const pSum = [strength[0]];
  for (let i = 1; i < n; i++) {
    pSum[i] = (pSum[i-1] + strength[i]) % mod;
  }
  const ppSum = pSum.reduce((acc, cur) => {
    acc.push((acc[acc.length-1] + cur) % mod);
    return acc;
  }, [0]);
  
  const right = Array(n).fill(n);
  let stack = [];
  for (let i = 0; i < n; i++) {
    const val = strength[i];
    while (stack.length && strength[stack[stack.length-1]] > val) {
      const j = stack.pop();
      right[j] = i;
    }
    stack.push(i);
  }
  
  const left = Array(n).fill(-1);
  stack = [];
  for (let i = n-1; i >= 0; --i) {
    const val = strength[i];
    while (stack.length && strength[stack[stack.length-1]] >= val) {
      const j = stack.pop();
      left[j] = i;
    }
    stack.push(i);
  }
  
  let res = 0;
  for (let i = 0; i < n; i++) {
    const val = strength[i];
    const l = left[i], r = right[i];
    const ln = i - l, rn = r - i;
    const lSum = ppSum[i] - ppSum[Math.max(l, 0)];
    const rSum = ppSum[r] - ppSum[i];
    // console.log({l, ln, lSum, r, rn, rSum})
    res = (res + Number(
        BigInt(strength[i]) *
        BigInt((((rSum * ln - lSum * rn) % mod) + mod) % mod) % 
        BigInt(mod)
      ) % mod) % mod;
  }
  return res;
};
