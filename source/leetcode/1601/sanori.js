/**
 * @param {number} n
 * @param {number[][]} requests
 * @return {number}
 */
var maximumRequests = function(n, requests) {
  if (n < 1) {
    return 0;
  }
  
  const inOut = Array(n).fill(0);
  let res = 0;
  const helper = (idx = requests.length - 1, reqs = 0) => {
    if (idx < 0) { // end of recursion
      for (let i = 0; i < n; i++) {
        if (inOut[i] !== 0) {
          return;
        }
      }
      res = Math.max(res, reqs);
      return;
    }
    const [f, t] = requests[idx]
    inOut[f]--;
    inOut[t]++;
    helper(idx - 1, reqs + 1);
    inOut[t]--;
    inOut[f]++;
    helper(idx - 1, reqs);
  }
  helper();
  return res;
};