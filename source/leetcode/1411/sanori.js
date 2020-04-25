/**
 * @param {number} n
 * @return {number}
 */
var numOfWays = function(n) {
  const mod = 1e9 + 7;
  const helper = (k) => {
    if (k <= 1) {
      return [6, 6];
    }
    const [u, l] = helper(k - 1);
    const nu = (3 * u + 2 * l) % mod;
    const nl = (2 * u + 2 * l) % mod;
    return [nu, nl];
  }
  const res = helper(n);
  return (res[0] + res[1]) % mod;
}
