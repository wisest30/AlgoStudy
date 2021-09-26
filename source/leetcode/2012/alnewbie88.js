/**
 * @param {number[]} nums
 * @return {number}
 */
var sumOfBeauties = function(nums) {
    let minVal = 100000;
    let minValsOnRightArr = new Array(nums.length).fill(0);
    for (let i = nums.length - 1; i >= 0; i--) {
        if (nums[i] < minVal) {
            minVal = nums[i];
        }
        minValsOnRightArr[i] = minVal;
    }
    
    let beautyScores = new Array(nums.length).fill(0);
    let maxValOnLeft = nums[0];
    for (let i = 1; i < nums.length - 1; i++) {
        if (maxValOnLeft < nums[i] && nums[i] < minValsOnRightArr[i + 1]) {
            beautyScores[i] = 2;
        }
        else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
            beautyScores[i] = 1;
        }
        
        if (nums[i] > maxValOnLeft) {
            maxValOnLeft = nums[i];
        }
    }
    
    return beautyScores.reduce((accum, curVal) => accum + curVal, 0);
};