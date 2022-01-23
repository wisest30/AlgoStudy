/**
 * @param {string} s
 * @param {number} k
 * @param {character} fill
 * @return {string[]}
 */
 var divideString = function(s, k, fill) {
  const n = s.length;
  const res = [];
  for (let i = 0; i < Math.ceil(n/k); i++) {
    res.push(s.slice(i*k, (i+1)*k));
  }
  const lastLen = res[res.length-1].length;
  if (lastLen < k) {
    const l = res.pop();
    res.push(l + fill.repeat(k-lastLen));
  }
  return res;
};
