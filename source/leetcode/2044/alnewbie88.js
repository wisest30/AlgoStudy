/**
 * @param {number[]} nums
 * @return {number}
 */
var countMaxOrSubsets = function(nums) {
    if (nums.length === 1) {
        return 1;
    }
    
    const maxBitOR = nums.reduce((accum, curVal) => accum | curVal);
    let q = [];
    q.push({idx: 0, accumBitOR:0});
    q.push({idx: 0, accumBitOR:nums[0]});
    
    let cnt = 0;
    while(q.length > 0) {
        const val = q.pop();
        if (val.idx === nums.length) {
            continue;
        }
        
        if (val.accumBitOR === maxBitOR) {
            cnt += Math.pow(2, nums.length - 1 - val.idx);
            continue;
        }
        
        q.push({idx: val.idx + 1, accumBitOR: val.accumBitOR});
        q.push({idx: val.idx + 1, accumBitOR: val.accumBitOR | nums[val.idx + 1]});
    }
    
    return cnt;
};