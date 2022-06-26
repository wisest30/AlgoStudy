/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var longestSubsequence = function(s, k) {
    let overGreater = false;
    let binary = '';
    for (let i = s.length - 1; i >= 0; i--) {
        const ch = s[i];
        if (ch === '0') {
            binary = ch + binary;
        } else if (overGreater) {
            continue;
        } else {
            if (parseInt(ch + binary, 2) > k) {
                overGreater = true;
            } else {
                binary = ch + binary;
            }
        }
    }
    
    return binary.length;
};