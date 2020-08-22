/**
 * @param {number} n
 * @param {number} k
 * @return {character}
 */
var findKthBit = function(n, k) {
  // console.log({n, k});
  if (n === 1) {
    return "0";
  }
  const d = 2 ** (n - 1);
  if (k < d) {
    return findKthBit(n-1, k);
  } else if (k > d) {
    return (findKthBit(n-1, 2 ** n - k) === "0") ? "1": "0";
  }
  return "1";
};