var longestIdealString = function(s, k) {
  const aCode = 'a'.charCodeAt(0);
  const n = s.length;
  const max = Array(26).fill(0);
  for (let i = 0; i < n; i++) {
    const c = s.charCodeAt(i) - aCode;
    const lo = Math.max(0, c - k), hi = Math.min(26, c + k + 1);
    max[c] = Math.max(...max.slice(lo, hi)) + 1;
  }
  return Math.max(...max);
};
