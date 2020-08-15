/**
 * @param {number[][]} grid
 * @return {number}
 */
var minSwaps = function(grid) {
  const n = grid.length;
  if (n < 1) {
    return 0;
  }
  const rPos = grid.map(r => {
    let i = n;
    for (; i > 0 && r[i-1] === 0; --i);
    return i;
  });
  let res = 0;
  for (let i = 0; i < n; i++) {
    if (rPos[i] <= i + 1) continue;
    let t = i+1;
    for(;t < n && rPos[t] > i + 1; t++);
    if (t >= n) {
      return -1;
    }
    // assert(rPos[t] <= i)
    for (let j = t; j > i; --j) {
      const tmp = rPos[j-1];
      rPos[j-1] = rPos[j];
      rPos[j] = tmp;
      res++;
    }
  }
  return res;
};