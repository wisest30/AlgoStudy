/**
 * @param {string} s
 * @return {boolean}
 */
var checkOnesSegment = function(s) {
    for (let i = 2; i < s.length; i++) {
        if (s[i - 1] === '0' && s[i] === '1') {
            return false;
        }
    }
    
    return true;
};