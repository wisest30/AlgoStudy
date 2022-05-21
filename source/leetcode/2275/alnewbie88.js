/**
 * @param {number[]} candidates
 * @return {number}
 */
var largestCombination = function(candidates) {
    let max = 1;
    for (let i = 0; i < 24; i++) { // 2^24 > 10^7
        let bitNum = 1 << i;
        let cnt = 0;
        candidates.forEach(num => {
            if (num & bitNum) {
                cnt++;
            }
        });
        
        max = Math.max(max, cnt);
    }
    
    return max;
};