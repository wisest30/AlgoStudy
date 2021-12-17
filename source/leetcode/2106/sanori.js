/**
 * @param {number[][]} fruits
 * @param {number} startPos
 * @param {number} k
 * @return {number}
 */
var maxTotalFruits = function (fruits, startPos, k) {
  const n = fruits.length;
  let lo = 0;
  for (; lo < n && fruits[lo][0] + k < startPos; lo++);
  let hi = lo, curSum = 0;
  for (; hi < n && fruits[hi][0] <= startPos; hi++) {
    curSum += fruits[hi][1];
  }
  let res = curSum;
  while (hi < n && fruits[hi][0] - startPos <= k) {
    while (fruits[lo][0] <= startPos &&
      Math.min(
        (startPos - fruits[lo][0]) * 2 + (fruits[hi][0] - startPos),
        (startPos - fruits[lo][0]) + (fruits[hi][0] - startPos) * 2
      ) > k) {
      curSum -= fruits[lo][1];
      lo++;
    }
    curSum += fruits[hi][1];
    res = Math.max(res, curSum);
    hi++;
  }
  return res;
};