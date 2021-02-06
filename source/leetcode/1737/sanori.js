const codeA = 'a'.charCodeAt(0);
const charFreq = (str) => {
  const n = str.length;
  const res = Array(26).fill(0);
  for (let i = 0; i < n; i++) {
    const idx = str.charCodeAt(i) - codeA;
    res[idx]++;
  }
  return res;
}

/**
 * @param {string} a
 * @param {string} b
 * @return {number}
 */
var minCharacters = function(a, b) {
  const aLen = a.length;
  const bLen = b.length;
  const freqA = charFreq(a);
  const freqB = charFreq(b);

  let max = 0;
  for (let i = 0; i < 26; i++) {
    max = Math.max(max, freqA[i] + freqB[i]);
  }

  let res = aLen + bLen - max;

  let aSum = 0, bSum = 0;
  for (let i = 0; i < 25; i++) {
    aSum += freqA[i];
    bSum += freqB[i];
    res = Math.min(res, aLen - aSum + bSum, bLen - bSum + aSum);
  }
  return res;
};
