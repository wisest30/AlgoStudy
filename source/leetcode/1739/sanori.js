/**
 * @param {number} n
 * @return {number}
 */
var minimumBoxes = function(n) {
  const floor = [1];
  const sum = [1];
  let i = 0;
  for (; sum[i] < n; i++) {
    floor[i+1] = floor[i] + (i + 2);
    sum[i+1] = sum[i] + floor[i+1];
  }

  if (sum[i] === n) {
    return floor[i];
  }
  let remain = n - sum[i-1];
  let res = floor[i-1];
  let add = 1;
  while (remain > 0) {
    remain -= add;
    res++;
    add++;
  }
  return res;
};
