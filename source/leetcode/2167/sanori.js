/**
 * @param {string} s
 * @return {number}
 */
var minimumTime = function (s) {
  const n = s.length;
  const left = [];
  left[0] = (s[0] === '1') ? 1 : 0;
  for (let i = 1; i < n; i++) {
    if (s[i] === '1') {
      left[i] = Math.min(i + 1, left[i - 1] + 2);
    } else {
      left[i] = left[i - 1];
    }
  }
  const right = [];
  right[n - 1] = (s[n - 1] === '1') ? 1 : 0;
  for (let i = n - 2; i >= 0; --i) {
    if (s[i] === '1') {
      right[i] = Math.min(n - i, right[i + 1] + 2);
    } else {
      right[i] = right[i + 1];
    }
  }
  let res = Math.min(left[n - 1], right[0]);
  for (let i = 0; i < n - 1; i++) {
    res = Math.min(res, left[i] + right[i + 1]);
  }
  // console.log({left, right});
  return res;
};