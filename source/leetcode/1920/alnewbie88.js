/**
 * @param {number[]} nums
 * @return {number[]}
 */
var buildArray = function(nums) {
    let ret = new Array(nums.length);
    for (let i = 0; i < nums.length; i++) {
        ret[i] = nums[nums[i]];
    }
    
    return ret;
};