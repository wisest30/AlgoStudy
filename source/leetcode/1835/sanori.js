/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number}
 */
 var getXORSum = function(arr1, arr2) {
  const BITS = 30;
  const countBits = (arr) => {
    const res = Array(BITS).fill(0);
    for (const a of arr) {
      for (let i = 0, b = 1; i < BITS; i++) {
        res[i] += ((a & b) === 0) ? 0 : 1;
        b <<= 1;
      }
    } 
    return res;
  }
  const counts1 = countBits(arr1);
  const counts2 = countBits(arr2);
  // console.log({counts1, counts2});
  let res = 0;
  for (let i = BITS-1; i >= 0; --i) {
    res <<= 1;
    if ((counts1[i] * counts2[i]) % 2 === 1) {
      res |= 1;
    }
  }
  return res;
};
