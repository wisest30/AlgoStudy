/**
 * @param {number} n
 * @return {number}
 */
var countVowelStrings = function(n) {
  const helper = (l, k = 5) => {
    if (l === 0) {
      return 1;
    }
    let res = 0;
    for (let i = 0; i < k; i++) {
      res += helper(l - 1, i + 1);
    }
    // console.log({l, k, res});
    return res;
  };
  return helper(n);
};