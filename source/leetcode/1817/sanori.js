/**
 * @param {number[][]} logs
 * @param {number} k
 * @return {number[]}
 */
var findingUsersActiveMinutes = function(logs, k) {
  const logDict = {};
  for (const [u, t] of logs) {
    if (logDict[u] === undefined) {
      logDict[u] = new Set();
    }
    logDict[u].add(t);
  }

  const res = Array(k).fill(0);
  for (const u in logDict) {
    const s = logDict[u].size;
    res[s - 1]++;
  }

  return res;
};
