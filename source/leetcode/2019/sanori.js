/**
 * @param {string} s
 * @param {number[]} answers
 * @return {number}
 */
 var scoreOfStudents = function(s, answers) {
  const n = s.length;
  
  const memo = {};
  memo[-1] = new Set();
  for (let i = 0; i < n/2; i++) {
    const idx = i * 100 + i;
    memo[idx] = new Set([Number(s[2*i])]);
  }
  
  const subRes = (l, r) => {
    if (l > r || l < 0 || r >= n/2) {
      return memo[-1];
    }
    const idx = l * 100 + r;
    if (memo[idx] === undefined) {
      const res = new Set();
      for (let i = l * 2 + 1; i < r * 2; i += 2) {
        const op = s[i];
        const lVals = subRes(l, i >> 1);
        const rVals = subRes((i >> 1) + 1, r);
        for (const lv of lVals) {
          for (const rv of rVals) {
            if (op === '*' && lv * rv <= 1000) {
              res.add(lv * rv);
            } else if (op === '+' && lv + rv <= 1000) {
              res.add(lv + rv);
            }
          }
        }
      }
      memo[idx] = res;
    }
    return memo[idx];
  };
  
  const point2s = subRes(0, n >> 1);
  const ans = eval(s);
  // console.log({point2s, memo});
  const ansFreq = answers.reduce((acc, cur) => {
    acc[cur] = acc[cur] + 1 || 1;
    return acc;
  }, {});
  
  let res = 0;
  for (const sa in ansFreq) {
    const san = Number(sa);
    if (san === ans) {
      res += 5 * ansFreq[sa];
    } else if (point2s.has(san)) {
      res += 2 * ansFreq[sa];
    }
  }
  return res;
};
