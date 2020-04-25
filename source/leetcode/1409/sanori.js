/**
 * @param {number[]} queries
 * @param {number} m
 * @return {number[]}
 */
var processQueries = function(queries, m) {
  const loc = {}
  for (let i = 0; i < m; i++) {
    loc[i+1] = i;
  }
  const res = [];
  for(const q of queries) {
    const l = loc[q];
    res.push(l);
    for (const k in loc) {
      const v = loc[k];
      if (v < l) {
        loc[k]++;
      }
    }
    loc[q] = 0;
  }
  return res;
};