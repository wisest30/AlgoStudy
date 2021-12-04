/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var getAverages = function(nums, k) {
    const subArrLen = k * 2 + 1;
    let subArrSum = undefined;
    let avgs = [];
    for (let i = 0; i < nums.length; i++) {    
        if (i < k || i >= nums.length - k) {
            avgs.push(-1);
            continue;
        }
        
        if (subArrSum === undefined) {
            subArrSum = 0;
            for (let j = -k; j <= k; j++) {
                subArrSum += nums[i + j];
            }
        } else {
            subArrSum = subArrSum - nums[i - k - 1] + nums[i + k];
        }
        
        avgs.push(Math.floor(subArrSum / subArrLen));
    }
    
    return avgs;
};
