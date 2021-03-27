/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
 var maximumScore = function(nums, k) {
  const n = nums.length;
  const numIdx = nums.map((x,i) => [x, i])
    .sort((a,b) => (a[0] !== b[0]) ? a[0] - b[0] : Math.abs(b[1] - k) - Math.abs(a[1] - k));

  let score = numIdx[0][0] * nums.length;
  let lo = 0, hi = n-1;
  for (let i = 0; i < n-1; i++) {
    const j = numIdx[i][1];
    const nextMin = numIdx[i+1][0];
    if (j === k) {
      return score;
    }
    if (j < k) {
      if (lo < j + 1) {
        lo = j+1;
      }
    } else { // j > k
      if (hi > j - 1) {
        hi = j-1;
      }
    }
    const newScore = (hi - lo + 1) * nextMin;
    if (newScore > score) {
      score = newScore;
    }
  }
  return score;
};
