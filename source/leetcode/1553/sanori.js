/**
 * @param {number} n
 * @return {number}
 */
var minDays = function(n) {
  const memo = {};
  const helper = (k, limit = k) => {
    // console.log({k, limit});
    if (k <= 2) {
      return k;
    }
    if (limit > k) {
      limit = k;
    }
    if (memo[k] === undefined) {
      let res = Infinity;
      if (k % 3 === 0) {
        res = Math.min(res, helper(k/3));
      }
      if (k % 2 === 0) {
        res = Math.min(res, helper(k/2));
      }
      if (limit > 0) {
        res = Math.min(res, helper(k - 1, Math.min(res, limit - 1)));
      }

      if (res != Infinity) {
        memo[k] = res + 1;
      }
      //console.log({memo});
    }
    return (memo[k] === undefined) ? Infinity : memo[k];
  }
  const res = helper(n);
  return res;
};