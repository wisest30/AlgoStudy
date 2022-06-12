/**
 * @param {number[]} nums
 * @param {number[][]} operations
 * @return {number[]}
 */
var arrayChange = function(nums, operations) {
    let map = new Map();   // numToIndex
    for (let i = 0; i < nums.length; i++) {
        map.set(nums[i], i);
    }
    
    operations.forEach(oper => {
        let index = map.get(oper[0]);
        nums[index] = oper[1];
        map.set(oper[1], index);
    });
    
    return nums;
};