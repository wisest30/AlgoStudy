/**
 * @param {number[]} piles
 * @return {number}
 */
var maxCoins = function(piles) {
  const n = Math.floor(piles.length/3);
  piles.sort((a,b) => b - a);
  let res = 0;
  for (let i = 0; i < n; i++) {
    res += piles[2 * i + 1];
  }
  return res;
};