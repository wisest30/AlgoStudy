/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
 var minSteps = function(s, t) {
  const aCode = 'a'.charCodeAt(0);
  const getFreq = (s) => {
    const res = Array(26).fill(0);
    const n = s.length;
    for (let i = 0; i < n; i++) {
      const ch = s.charCodeAt(i) - aCode;
      res[ch]++;
    }
    return res;
  }
  const sFreq = getFreq(s);
  const tFreq = getFreq(t);
  let res = 0;
  for (let i = 0; i < 26; i++) {
    res += Math.abs(sFreq[i] - tFreq[i]);
  }
  return res;
};
