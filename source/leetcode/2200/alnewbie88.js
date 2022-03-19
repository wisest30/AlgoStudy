/**
 * @param {number[]} nums
 * @param {number} key
 * @param {number} k
 * @return {number[]}
 */
var findKDistantIndices = function(nums, key, k) {
    let set = new Set();
    for (let j = 0; j < nums.length; j++) {
        if (nums[j] === key) {
            for (let i = -k; i <= k; i++) {
                let index = j + i;
                if (index >= 0 && index < nums.length) {
                    set.add(index);
                }
            }
        }
    }
    
    return Array.from(set).sort((a, b) => { return a - b; });
}