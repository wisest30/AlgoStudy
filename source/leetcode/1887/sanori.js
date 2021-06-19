/**
 * @param {number[]} nums
 * @return {number}
 */
 var reductionOperations = function(nums) {
  const freq = nums.reduce((acc, cur) => {
    acc[cur] = acc[cur] + 1 || 1;
    return acc;
  }, {});
  const fArr = Object.entries(freq);
  fArr.sort((a,b) => b[0] - a[0]);
  let res = 0, sum = 0;
  for (let i = 0; i < fArr.length - 1; i++) {
    sum += fArr[i][1];
    res += sum;
  }
  return res;
};
