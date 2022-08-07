/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function(nums) {
    let set = new Set(nums);
    return set.has(0) ? set.size - 1 : set.size;
};