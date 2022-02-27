/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countPairs = function(nums, k) {
    let getGCD = function(a, b) {
        if (b === 0) {
            return a;
        }
        return getGCD(b, a % b);
    }
    
    let gcdMap = new Map();
    let ret = 0;
    for (let i = 0; i < nums.length; i++) {
        let gcd = getGCD(nums[i], k);
        gcdMap.forEach((value, key) => {
            const gcd2 = key;
            const count = value;
            if (gcd * gcd2 % k === 0) {
                ret += count;
            }
        });
        
        if (!gcdMap.has(gcd)) {
            gcdMap.set(gcd, 1);
        } else {
            gcdMap.set(gcd, gcdMap.get(gcd) + 1);
        }
    }
    
    return ret;
};