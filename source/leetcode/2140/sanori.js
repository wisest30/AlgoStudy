/**
 * @param {number[][]} questions
 * @return {number}
 */
 var mostPoints = function(questions) {
  const n = questions.length;
  const dp = Array(n).fill(0);
  dp[n-1] = questions[n-1][0];
  for (let i = n-2; i >= 0; --i) {
    const next = i + questions[i][1] + 1;
    let res = questions[i][0] + ((next < n) ? dp[next] : 0);
    dp[i] = Math.max(res, dp[i+1]);
  }
  return dp[0];
};
