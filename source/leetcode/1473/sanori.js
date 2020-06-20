/**
 * @param {number[]} houses
 * @param {number[][]} cost
 * @param {number} m
 * @param {number} n
 * @param {number} target
 * @return {number}
 */
var minCost = function(houses, cost, m, n, target) {
  const memo = {};
  const helper = (mm, tt, lastColor) => {
    if (tt <= 0) return Infinity;
    if (mm <= 0) {
      return (tt === 1) ? 0 : Infinity;
    }
    const idx = `${mm},${tt},${lastColor}`;
    if (memo[idx] === undefined) {
      const curColor = houses[mm-1];
      if (curColor !== 0) {
        const nextT = (curColor === lastColor) ? tt : tt - 1;
        memo[idx] = helper(mm - 1, nextT, curColor);
      } else {
        let res = Infinity;
        for (let c = 0; c < n; c++) {
          const curCost = cost[mm-1][c];
          const curColor = c + 1;
          const nextT = (lastColor === 0 || curColor === lastColor) ? tt : tt - 1;
          res = Math.min(res, helper(mm - 1, nextT, curColor) + curCost);
        }
        memo[idx] = res;
      }
    }
    return memo[idx];
  };
  
  let res = helper(m, target, houses[m-1]);
  // console.log({memo});
  return (res == Infinity) ? -1: res;
};
