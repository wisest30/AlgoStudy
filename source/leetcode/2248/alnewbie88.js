/**
 * @param {number[][]} nums
 * @return {number[]}
 */
var intersection = function(nums) {
    let m = new Map();
    for (let i = 0; i < nums.length; i++) {
        nums[i].forEach(num => {
            if (m.has(num)) {
                m.set(num, m.get(num) + 1)
            } else {
                m.set(num, 1);
            }
        });
    }
    
    let ans = [];
    m.forEach((value, key) => {
        if (value === nums.length) {
            ans.push(key);
        }
    });
    
    ans.sort((a, b) => { return a - b; });
    return ans;
};