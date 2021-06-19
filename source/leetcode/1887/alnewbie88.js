/**
 * @param {number[]} nums
 * @return {number}
 */
var reductionOperations = function(nums) {
    nums.sort(function(a, b) { return b - a; });

    let splited = [];
    let curIdx = 0;
    for (let i = 1; i < nums.length; i++) {
        if (nums[curIdx] === nums[i]) {
            continue;
        }
        
        splited.push(i - curIdx);
        curIdx = i;
    }
    
    for (let i = 1; i < splited.length; i++) {
        splited[i] += splited[i - 1];
    }
    
    return splited.reduce(function (accum, curVal) { return accum + curVal; }, 0);
};