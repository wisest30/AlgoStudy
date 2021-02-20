/**
 * @param {number[]} nums
 * @return {boolean}
 */
var check = function(nums) {
    let arrLength = nums.length;
    for (let i = 0; i < arrLength; i++) {
        const lastElamValue = nums[arrLength - 1];
        for (let j = arrLength - 1; j >= 0; j--) {
            if (j === 0) {
                nums[0] = lastElamValue;
            } else {
                nums[j] = nums[j - 1];
            }
        }
        
        let sorted = true;
        for (let j = 0; j < arrLength - 1; j++) {
            if (nums[j] > nums[j + 1]) {
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