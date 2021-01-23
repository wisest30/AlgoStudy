/**
 * @param {number[]} jobs
 * @param {number} k
 * @return {number}
 */
var minimumTimeRequired = function(jobs, k) {
  const n = jobs.length;
  jobs.sort((a, b) => b - a);
  console.log({jobs});

  // upper bound: simple solution
  const w = Array(k).fill(0);
  for (const j of jobs) {
    let minIdx = 0, minVal = Infinity;
    for (let i = 0; i < k; i++) {
      if (w[i] < minVal) {
        minIdx = i;
        minVal = w[i];
      }
    }
    w[minIdx] += j;
  }
  const upper = Math.max(...w);

  // brand & bound;
  let res = upper;
  const conf = Array(k).fill(0);
  const traverse = (j = 0) => {
    if (j >= n) {
      res = Math.min(res, Math.max(...conf));
      return;
    }
    for (let i = 0; i < k; i++) {
      if (conf[i] + jobs[j] > res) continue;
      conf[i] += jobs[j];
      traverse(j+1);
      conf[i] -= jobs[j];
    }
  }
  traverse(0);
  return res;
};
