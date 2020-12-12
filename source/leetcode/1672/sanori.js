/**
 * @param {number[][]} accounts
 * @return {number}
 */
var maximumWealth = function(accounts) {
  const w = accounts
    .map(x => x.reduce((a,b) => a + b, 0));
  return Math.max(...w);
};
