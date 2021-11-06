/**
 * @param {number[]} nums
 * @return {number}
 */
var smallestEqual = function(nums) {
    let smallestEqualIdx = -1;
    for (let i = 0; i < nums.length; i++) {
        if (i % 10 === nums[i]) {
            smallestEqualIdx = i;
            break;
        }
    }
    
    return smallestEqualIdx;
};