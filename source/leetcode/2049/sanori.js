/**
 * @param {number[]} parents
 * @return {number}
 */
 var countHighestScoreNodes = function(parents) {
  const n = parents.length;
  const childs = Array(n).fill(null).map(() => []);
  for (let i = 1; i < n; i++) {
    childs[parents[i]].push(i);
  }

  const scoreFreq = {};
  const traverse = (u) => {
    let counts = [], sum = 1;
    for (const v of childs[u]) {
      const vn = traverse(v);
      counts.push(vn);
      sum += vn;
    }
    const prods = counts.reduce((a, b) => a * b, 1);
    const pp = prods * ((sum === n) ? 1 : (n - sum));
    scoreFreq[pp] = scoreFreq[pp] + 1 || 1;
    return sum;
  };
  traverse(0);

  const maxScore = Math.max(...Object.keys(scoreFreq));
  return scoreFreq[maxScore];
};
