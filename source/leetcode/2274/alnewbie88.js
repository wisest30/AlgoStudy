/**
 * @param {number} bottom
 * @param {number} top
 * @param {number[]} special
 * @return {number}
 */
var maxConsecutive = function(bottom, top, special) {
    special.push(bottom - 1);
    special.push(top + 1);
    special.sort((a, b) => { return a - b; });
    
    let max = 0;
    for (let i = 1; i < special.length; i++) {
        max = Math.max(max, special[i] - special[i - 1] - 1);
    }
    
    return max;
};