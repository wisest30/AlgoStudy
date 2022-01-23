/**
 * @param {number} n
 * @param {number[]} batteries
 * @return {number}
 */
 var maxRunTime = function(n, batteries) {
  batteries.sort((a, b) => a - b);
  let sum = batteries.reduce((a,b) => a + b, 0);
  let numComp = n;
  while (batteries[batteries.length-1] > sum/numComp) {
    const b = batteries.pop();
    sum -= b;
    numComp--;
  }
  return Math.floor(sum/numComp);
};
