/**
 * @param {number[]} stones
 * @return {number}
 */
var stoneGameVII = function(stones) {
  const n = stones.length;
  const preSum = stones.reduce((acc, cur) => {
    acc.push(acc[acc.length-1] + cur);
    return acc;
  }, [0]);
  
  const memo = {};
  const helper = (lo = 0, hi = n) => {
    if (hi - lo <= 1) {
      return 0;
    }
    
    const idx = `${lo},${hi}`;
    if (memo[idx] === undefined) {
      let res =  (preSum[hi] - preSum[lo+1]) - helper(lo+1, hi);
      let res2 = (preSum[hi-1] - preSum[lo]) - helper(lo, hi-1);
      res = Math.max(res, res2);
      memo[idx] = res;
    }
    return memo[idx];
  };
  const res = helper();
  return res;
};