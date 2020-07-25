/**
 * @param {string} s
 * @return {number}
 */
var numSub = function(s) {
  const mod = 1e9 + 7;
  const n = s.length;
  const freq = {};
  let cnt = 0;
  for (let i = 0; i < n; i++) {
    if (s[i] === '1') {
      cnt++;
    } else {
      freq[cnt] = freq[cnt] + 1 || 1;
      cnt = 0;
    }
  }
  if (cnt > 0) {
    freq[cnt] = freq[cnt] + 1 || 1;
  }
  let res = 0;
  for (let cnt in freq) {
    cnt = Number(cnt);
    const f = freq[cnt];
    res = (res + f * cnt * (cnt + 1) / 2) % mod;
  }
  return res;
};