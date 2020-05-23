/**
 * @param {number[]} arr
 * @return {number}
 */
var countTriplets = function(arr) {
  const n = arr.length;
  const preXor = arr.reduce((acc, cur) => {
    acc.push(acc[acc.length - 1] ^ cur);
    return acc;
  }, [0]);
  let res = 0;
  for (let i = 0; i < n - 1; i++) {
    for (let j = i + 1; j < n; j++) {
      for (let k = j; k < n; k++) {
        if ((preXor[i] ^ preXor[j]) === (preXor[j] ^ preXor[k+1])) {
          res++;
        }
      }
    }
  }
  return res;
};