/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var partitionArray = function(nums, k) {
    nums.sort((a, b) => { return a - b; });
    
    let min = 100001;
    let max = 0;
    let cnt = 1;
    nums.forEach(num => {
        min = Math.min(min, num);
        max = Math.max(max, num);
        if (max - min > k) {
            min = max = num;
            cnt++;
        }
    });
    
    return cnt;
};