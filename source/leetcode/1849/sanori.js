/**
 * @param {string} s
 * @return {boolean}
 */
 var splitString = function(s) {
  const n = s.length;
  const cand = Array(n).fill(null).map(() => new Set());
  for (let i = n - 1; i >= 0; --i) {
    const a = s.slice(i);
    cand[i].add(Number(a));
    for (let j = i + 1; j < n; j++) {
      const b = s.slice(i, j);
      if (cand[j].has(Number(b) - 1)) {
        cand[i].add(Number(b));
      }
    }
  }
  return (cand[0].size > 1);
};
