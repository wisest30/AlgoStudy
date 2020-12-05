/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToMakeFair = function(nums) {
  const n = nums.length;
  const sum = [[0], [0]];
  for (let i = 0; i < n; i++) {
    const idx = Math.floor(i / 2);
    const parity = i % 2;
    sum[parity][idx+1] = sum[parity][idx] + nums[i];
  }

  const sMax = [sum[0][sum[0].length-1], sum[1][sum[1].length -1]];
  console.log({sum, sMax});

  let res = 0;
  for (let i = 0; i < n; i++) {
    const idx = Math.floor(i / 2) + 1;
    const parity = i % 2;
    if (parity) {
      const s0 = sum[0][idx] + sMax[1] - sum[1][idx];
      const s1 = sum[1][idx-1] + sMax[0] - sum[0][idx];
      if (s0 === s1) {
        res++;
      }
    } else {
      const s0 = sum[0][idx-1] + sMax[1] - sum[1][idx-1];
      const s1 = sum[1][idx-1] + sMax[0] - sum[0][idx];
      if (s0 === s1) {
        res++;
      }
    }
  }

  return res;
};
