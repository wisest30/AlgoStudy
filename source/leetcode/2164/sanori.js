/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortEvenOdd = function (nums) {
  const n = nums.length;
  const arr = [[], []];
  for (let i = 0; i < n; i++) {
    arr[i % 2].push(nums[i]);
  }
  arr[0].sort((a, b) => a - b);
  arr[1].sort((a, b) => b - a);
  const res = [];
  for (let i = 0; i < n; i++) {
    res[i] = arr[i % 2][Math.floor(i / 2)];
  }
  return res;
};
