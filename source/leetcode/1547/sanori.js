/**
 * @param {number} n
 * @param {number[]} cuts
 * @return {number}
 */
var minCost = function(n, cuts) {
  const m = cuts.length;
  cuts.push(0);
  cuts.push(n);
  cuts.sort((a,b) => a - b);
  // console.log({cuts});
  
  const memo = {};
  const helper = (a, b) => {
    if (a >= b) {
      return Infinity;
    }
    if (b - a === 1) {
      return 0;
    }
    const idx = `${a},${b}`;
    if (memo[idx] === undefined) {
      const len = cuts[b] - cuts[a];
      let res = Infinity
      for (let i = a + 1; i < b; i++) {
        res = Math.min(res,
              helper(a, i) + helper(i, b));
      }
      memo[idx] = res + len;
    }
    return memo[idx];
  };
  
  const res = helper(0, m + 1);
  // console.log({memo});
  return res;
};