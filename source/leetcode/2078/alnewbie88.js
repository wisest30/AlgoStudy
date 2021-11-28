/**
 * @param {number[]} colors
 * @return {number}
 */
var maxDistance = function(colors) {
    const n = colors.length;
    let maxDist = 0;
    for (let i = 0; i < n; i++) {
        for (let j = n - 1; j >= 0; j--) {
            if (i !== j && colors[i] !== colors[j]) {
                maxDist = Math.max(maxDist, Math.abs(j - i));
                break;
            }
        }
    }
    
    return maxDist;
};