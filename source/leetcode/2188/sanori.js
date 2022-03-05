/**
 * @param {number[][]} tires
 * @param {number} changeTime
 * @param {number} numLaps
 * @return {number}
 */
 var minimumFinishTime = function(tires, changeTime, numLaps) {
  const n = tires.length;
  const minTime = Math.min(...tires.map(x => x[0]));
  const oneTire = Array(20).fill(Infinity);
  // const Limit = minTime + changeTime + 1;
  const Limit = 2e5;
  for (const [f, r] of tires) {
    let total = f, cur = f;
    for (let i = 0; i < 20 && total <= Limit; i++) {
      oneTire[i] = Math.min(oneTire[i], total);
      cur *= r;
      total += cur;
    }
  }
  const dp = [];
  for (let i = 0; i < numLaps; i++) {
    dp[i] = (i < 20) ? oneTire[i] : Infinity;
    for (let j = 0; j < i/2; j++) {
      dp[i] = Math.min(dp[i], dp[j] + changeTime + dp[i-j-1]);
    }
  }
  return dp[numLaps-1];
};
