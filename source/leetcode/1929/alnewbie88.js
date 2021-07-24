/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getConcatenation = function(nums) {
    let n = nums.length;
    let ans = new Array(n * 2);
    for (let i = 0; i < 2; i++) {
        for (let j = 0; j < n; j++) {
            ans[(i * n) + j] = nums[j];
        }
    }
    return ans;
};