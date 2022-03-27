/**
 * @param {number[]} nums
 * @return {number}
 */
var countHillValley = function(nums) {
    // remove duplicate
    for (let i = 1; i < nums.length;) {
        if (nums[i] === nums[i - 1]) {
            nums.splice(i, 1);
            continue;
        }
        i++;
    }
    
    let cnt = 0;
    for (let i = 1; i < nums.length - 1; i++) {
        const isHill = nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
        const isValley = nums[i] < nums[i - 1] && nums[i] < nums[i + 1];
        if (isHill || isValley) {
           cnt++;
        }
    }
    
    return cnt;
};