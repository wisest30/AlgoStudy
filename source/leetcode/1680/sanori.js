const mod = 1e9 + 7;
/**
 * @param {number} n
 * @return {number}
 */
var concatenatedBinary = function(n) {
  let res = 0;
  for (let i = 1; i <= n; i++) {
    const bStr = i.toString(2);
    for (let j = 0; j < bStr.length; j++) {
      res = (res * 2 + Number(bStr[j])) % mod;
    }
  }
  return res;
};
