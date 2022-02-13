/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortEvenOdd = function(nums) {
    let odds = [];
    let evens = [];
    for (let i = 0; i < nums.length; i++) {
        if (i % 2) {
            odds.push(nums[i]);
        } else {
            evens.push(nums[i]);
        }
    }
    
    odds.sort((a, b) => { return b - a; });
    evens.sort((a, b) => { return a - b; });
    
    let oddsIndex = 0;
    let evensIndex = 0;
    let res = [];
    for (let i = 0; i < odds.length + evens.length; i++) {
        if (i % 2) {
            res.push(odds[oddsIndex++]);
        } else {
            res.push(evens[evensIndex++]);
        }
    }
    
    return res;
};