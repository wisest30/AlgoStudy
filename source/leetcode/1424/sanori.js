/**
 * @param {number[][]} nums
 * @return {number[]}
 */
var findDiagonalOrder = function(nums) {
  const m = nums.length;  
  const midArr = [];
  for(let r = 0; r < m; r++) {
    const cl = nums[r].length;
    for (let c = 0; c < cl; c++) {
      midArr.push([r+c, r, nums[r][c]]);
    }
  }
  midArr.sort((a, b) => (a[0] !== b[0]) ? (a[0] - b[0]) : (b[1] - a[1]));
  return midArr.map(x => x[2]);
};