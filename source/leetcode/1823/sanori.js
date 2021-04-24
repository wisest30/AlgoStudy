/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
 var findTheWinner = function(n, k) {
  let s = 0;
  const f = Array(n).fill(null).map((_, i) => i + 1);
  while (n > 1) {
    s = (s + k - 1) % n;
    n--;
    f.splice(s, 1);
    // console.log({s, n, f});
  }
  return f[0];
};
