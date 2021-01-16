const mod = 1e9 + 7;
/**
 * @param {number[]} deliciousness
 * @return {number}
 */
var countPairs = function(deliciousness) {
  const freq = deliciousness.reduce((acc, cur) => {
    acc[cur] = acc[cur] + 1 || 1;
    return acc;
  }, {});
  let res = 0;
  for (const elem in freq) {
    const d = Number(elem);
    for (let i = 0; i <= 21; i++) {
      const target = (1 << i) - d;
      // console.log({d, fd: freq[d], target, f:freq[target]});
      if (target === d) {
        res = (res + freq[d] * (freq[d] - 1) / 2) % mod;
      } else if (freq[target] > 0) {
        res = (res + freq[d] * freq[target]) % mod;
      }
      // console.log({res});
    }
    delete freq[d];
  }
  return res;
};