/**
 * @param {number[]} nums
 * @param {number} limit
 * @param {number} goal
 * @return {number}
 */
var minElements = function(nums, limit, goal) {
    let sum = nums.reduce((accum, cur) => accum + cur);
    let diff = Math.abs(goal - sum);
    return Math.ceil(diff / limit);
};