/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} p
 * @return {number}
 */
var countDistinct = function(nums, k, p) {
    let set = new Set();
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            const subArr = nums.slice(i, j + 1);
            const subArrStr = subArr.join(',');
            if (set.has(subArrStr)) {
                continue;
            }
            
            let divisibleCnt = 0;
            subArr.forEach(num => { if (num % p === 0) divisibleCnt++; });
            if (divisibleCnt <= k) {
                set.add(subArrStr);
            }
        }
    }
    
    return set.size;
};