/**
 * @param {number[]} capacity
 * @param {number[]} rocks
 * @param {number} additionalRocks
 * @return {number}
 */
var maximumBags = function(capacity, rocks, additionalRocks) {
    const n = capacity.length;
    let remainCap = new Array(n);
    for (let i = 0; i < n; i++) {
        remainCap[i] = capacity[i] - rocks[i];
    }
    
    remainCap.sort((a, b) => { return a - b; });
    
    let cnt = 0;
    for (let i = 0; i < n; i++) {
        if (remainCap[i] > additionalRocks) {
            break;
        }
        additionalRocks -= remainCap[i];
        cnt++;
    }
    
    return cnt;
};