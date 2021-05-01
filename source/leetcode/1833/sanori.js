/**
 * @param {number[]} costs
 * @param {number} coins
 * @return {number}
 */
 var maxIceCream = function(costs, coins) {
  costs.sort((a, b) => a - b);
  let res = 0, sum = 0;
  for (let i = 0; i < costs.length; i++) {
    if (sum + costs[i] > coins) {
      break;
    }
    sum += costs[i];
    res++;
  }
  return res;
};
