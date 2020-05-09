/**
 * @param {number[]} cardPoints
 * @param {number} k
 * @return {number}
 */
var maxScore = function(cardPoints, k) {
  const n = cardPoints.length;
  const preSum = [0];
  const sufSum = [0];
  const lim = Math.min(k, n-1);
  for (let i = 0; i <= lim; i++) {
    preSum[i+1] = preSum[i] + cardPoints[i];
    sufSum[i+1] = sufSum[i] + cardPoints[n - i - 1];
  }
  
  let res = 0;
  for (let i = 0; i <= k; i++) {
    res = Math.max(res, preSum[i] + sufSum[k-i]);
  }
  
  return res;
};