/**
 * @param {string[]} pizza
 * @param {number} k
 * @return {number}
 */
var ways = function(pizza, k) {
  const mod = 1e9 + 7;  
  const m = pizza.length;
  if (m < 1 || k < 1) {
    return 0;
  }
  const n = pizza[0].length;
  const preApple = Array(m+1).fill(null).map(() => Array(n+1).fill(0));
  for(let r = 1; r <= m; r++) {
    for (let c = 1; c <= n; c++) {
      const apple = ((pizza[r-1][c-1] === 'A') ? 1 : 0); 
      preApple[r][c] = preApple[r-1][c] + preApple[r][c-1] -
                        preApple[r-1][c-1] + apple;
    }
  }
  // console.log({m, n, preApple});
  const memo = {};
  const helper = (r, c, kk) => {
    if (kk === 1) {
      const remain =  preApple[m][n] - preApple[r][n] -
              preApple[m][c] + preApple[r][c];
      if (remain < 1) {
        return 0;
      } else {
        return 1;
      }
    }
    const idx = `${r},${c},${kk}`;
    if (memo[idx] === undefined) {
      let res = 0;
      for (let rr = r + 1; rr < m; rr++) {
        const nA = preApple[rr][n] - preApple[r][n] - preApple[rr][c] + preApple[r][c];
        if (nA > 0) {
          res = (res + helper(rr, c, kk-1)) % mod;
        }
      }

      for (let cc = c + 1; cc < n; cc++) {
        const nA = preApple[m][cc] - preApple[m][c] - preApple[r][cc] + preApple[r][c];
        if (nA > 0) {
          res = (res + helper(r, cc, kk-1)) % mod;
        }
      }
      memo[idx] = res;
    }
    return memo[idx];
  };
  const res = helper(0, 0, k);
  // console.log({memo});
  return res;
};
