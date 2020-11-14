/**
 * @param {number[]} destination
 * @param {number} k
 * @return {string}
 */
var kthSmallestPath = function(destination, k) {
  const fact = [1n];
  for (let i = 1; i <= 30; i++) {
    fact[i] = BigInt(i) * fact[i-1];
  }
  let [v, h] = destination;
  const resArr = [];
  let cur = 0;
  while (v > 0 && h > 0 && cur !== k - 1) {
    let cnt = Number(fact[v + h - 1] / fact[v] / fact[h-1]);
    if (cur + cnt >= k) {
      resArr.push('H');
      h--;
    } else {
      cur += cnt;
      resArr.push('V');
      v--;
    }
  }
  while (h > 0) {
    resArr.push('H');
    h--;
  }
  while (v > 0) {
    resArr.push('V');
    v--;
  }
  return resArr.join('');
};