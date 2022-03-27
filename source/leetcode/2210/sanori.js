/**
 * @param {number[]} nums
 * @return {number}
 */
var countHillValley = function(nums) {
  const n = nums.length;
  let res = 0;
  for (let  i = 1; i < n-1; i++) {
    if (nums[i] === nums[i-1]) continue;
    let lIdx = i - 1;
    for (;lIdx >= 0 && nums[lIdx] === nums[i]; --lIdx);
    if (nums[lIdx] === nums[i]) continue;
    let rIdx = i + 1;
    for (;rIdx < n && nums[rIdx] === nums[i]; rIdx++);
    if ((nums[lIdx] < nums[i] && nums[i] > nums[rIdx]) || 
        (nums[lIdx] > nums[i] && nums[i] < nums[rIdx])) {
      res++;
    }
  }
  return res;
};

