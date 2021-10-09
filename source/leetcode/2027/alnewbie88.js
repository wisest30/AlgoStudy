/**
 * @param {string} s
 * @return {number}
 */
var minimumMoves = function(s) {
    let minMoves = 0;
    for (let i = 0; i < s.length;) {
        if (s[i] === 'X') {
            minMoves++;
            i += 3;
        } else {
            i++;
        }
    }
    
    return minMoves;
};