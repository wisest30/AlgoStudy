/**
 * @param {number[]} nums
 * @return {number[]}
 */
var recoverArray = function (nums) {
  const n = nums.length;
  const freq = nums.reduce((acc, cur) => {
    acc[cur] = acc[cur] + 1 || 1;
    return acc;
  }, {});
  const vals = Object.keys(freq).map(Number).sort((a, b) => a - b);

  const v0 = vals[0];
  for (let i = 1; i < vals.length; i++) {
    const vi = vals[i];
    const k2 = vi - v0;
    if (k2 % 2 === 1) continue;

    const counter = Object.assign({}, freq);
    let remain = n - counter[v0] * 2, matched = true;
    counter[v0 + k2] -= counter[v0];
    const k = k2 / 2;
    const res = Array(counter[v0]).fill(v0 + k);
    counter[v0] = 0;
    for (let j = 1; j < vals.length && matched; j++) {
      const vj = vals[j];
      if (counter[vj] === 0) continue;
      if (counter[vj + k2]) {
        const d = Math.min(counter[vj], counter[vj + k2]);
        counter[vj] -= d;
        counter[vj + k2] -= d;
        for (let l = 0; l < d; l++) {
          res.push(vj + k);
        }
        remain -= 2 * d;
      } else {
        matched = false;
      }
    }
    if (matched) {
      return res;
    }
  }
  return [];
};
