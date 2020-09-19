/**
 * @param {string} s
 * @param {number[]} cost
 * @return {number}
 */
var minCost = function(s, cost) {
  const n = s.length;
  let res = 0;
  let buf = [];
  for (let i = 0; i < n; i++) {
    if (s[i-1] === s[i]) {
      buf.push(cost[i-1]);
    } else if (buf.length > 0) {
      buf.push(cost[i-1]);
      const max = Math.max(...buf);
      const sum = buf.reduce((a, b) => a + b, 0);
      res += (sum - max);
      buf = [];
    } 
  }
  if (buf.length > 0) {
    buf.push(cost[n-1]);
    const max = Math.max(...buf);
    const sum = buf.reduce((a, b) => a + b, 0);
    res += (sum - max);
  }
  
  return res;
};