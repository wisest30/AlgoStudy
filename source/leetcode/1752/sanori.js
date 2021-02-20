/**
 * @param {number[]} nums
 * @return {boolean}
 */
var check = function(nums) {
  const n = nums.length;
  for (let i = 0; i < n; i++) {
    let sorted = true;
    for (let j = 0; j < n - 1; j++) {
      if (nums[(i+j) % n] > nums[(i+j+1) % n]) {
        sorted = false;
        break;
      }
    }
    if (sorted) {
      return true;
    }
  }
  return false;
};
