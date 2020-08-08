/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLengthOfOptimalCompression = function(s, k) {
  const n = s.length;
  const memo = {};
  const dp = (l, kk, lastCh = '', cnt = 0) => {
    if (kk < 0) {
      return Infinity;
    } else if (l >= n) {
      return 0;
    }
    const idx = `${l},${kk},${lastCh},${cnt}`;
    if (memo[idx] === undefined) {
      let res;
      if (s[l] === lastCh) {
        res = dp(l+1, kk, lastCh, cnt+1);
        if ([1, 9, 99].indexOf(cnt) >= 0) {
          res++;
        }
      } else {
        res = Math.min(
          1 + dp(l+1, kk, s[l], 1),
          dp(l+1, kk-1, lastCh, cnt)
        );
      }
      memo[idx] = res;
    }
    return memo[idx];
  };
  const res = dp(0, k);
  return res;
};