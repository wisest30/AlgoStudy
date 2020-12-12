/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var mostCompetitive = function(nums, k) {
  const n = nums.length;
  const res = [];
  for (let i = 0; i < n; i++) {
    while(res.length > (i + k -n) && res[res.length-1] > nums[i]) {
      res.pop();
    }
    if (res.length < k){
      res.push(nums[i]);
    }
  }
  return res;
};
