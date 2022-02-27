/**
 * @param {string} s
 * @param {number} repeatLimit
 * @return {string}
 */
 var repeatLimitedString = function(s, repeatLimit) {
  const n = s.length;
  const aCode = 'a'.charCodeAt(0);
  const freq = Array(26).fill(0);
  for (let i = 0; i < n; i++) {
    const c = s.charCodeAt(i) - aCode;
    freq[c]++;
  }
  const res = [];
  let deferred = -1;
  for (let i = 25; i >= 0; --i) {
    if (freq[i] > 0) {
      const ch = String.fromCharCode(i + aCode);
      if (deferred !== -1) {
        freq[i]--;
        res.push(ch);
        i = deferred + 1;
        deferred = -1;
      } else {
        const cnt = Math.min(freq[i], repeatLimit);
        freq[i] -= cnt;
        res.push(ch.repeat(cnt));
        if (freq[i] > 0) {
          deferred = i;
        }
      }
    }
  }

  return res.join('');
};
