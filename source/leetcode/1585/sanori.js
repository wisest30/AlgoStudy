/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isTransformable = function(s, t) {
  const code0 = '0'.charCodeAt(0);
  const n = s.length;
  const sPos = Array(10).fill(null).map(() => []);
  for (let i = n - 1; i >= 0; --i) {
    const d = s.charCodeAt(i) - code0;
    sPos[d].push(i);
  }
  
  console.log({sPos});
  for (let i = 0; i < n; i++) {
    const d = t.charCodeAt(i) - code0;
    if (sPos[d].length < 1) {
      return false;
    }
    const sp = sPos[d][sPos[d].length-1];
    
    for (let j = 0; j < d; j++) {
      const p = sPos[j];
      if (p.length < 1) continue;
      const jp = p[p.length-1];
      if (jp < sp) {
        return false;
      }
    }
    sPos[d].pop();
  }
  return true;
};
