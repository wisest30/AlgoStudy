/**
 * @param {number[]} customers
 * @param {number} boardingCost
 * @param {number} runningCost
 * @return {number}
 */
var minOperationsMaxProfit = function(customers, boardingCost, runningCost) {
  const n = customers.length;
  let maxRun = 0, maxProfit = 0;
  for (let i = 0, wait = 0, profit = 0, numRun = 0;
       i < n || wait > 0;) {
    if (i < n) {
      wait += customers[i++];
    }
    const nBoard = Math.min(4, wait);
    profit += boardingCost * nBoard - runningCost;
    wait -= nBoard;
    numRun++;
    if (profit > maxProfit) {
      maxProfit = profit;
      maxRun = numRun;
    }
  }
  return (maxProfit > 0) ? maxRun : -1;
};