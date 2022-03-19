/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumTop = function(nums, k) {
    const n = nums.length;
    if (n === 1 && k % 2 === 1) {
        return -1;
    }
    
    let max = k < n ? nums[k] : -1;
    for (let i = 0; i < Math.min(n, k - 1); i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    
    return max;
};