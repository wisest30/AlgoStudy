/**
 * @param {number[]} nums
 * @return {number}
 */
var maxAscendingSum = function(nums) {
    let maxSum = nums[0];
    let startIdx = 0;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] <= nums[i - 1]) {
            let sum = nums.slice(startIdx, i).reduce((accum, curVal) => accum + curVal, 0);
            if (sum > maxSum) {
                maxSum = sum;
            }
            startIdx = i;
        } 
    }
    
    let sum = nums.slice(startIdx, nums.length).reduce((accum, curVal) => accum + curVal, 0);
    if (sum > maxSum) {
        maxSum = sum;
    }
    
    return maxSum;
};