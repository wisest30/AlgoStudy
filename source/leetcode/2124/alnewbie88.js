/**
 * @param {string} s
 * @return {boolean}
 */
var checkString = function(s) {
    const sLen = s.length;
    for (let i = 0; i < sLen; i++) {
        if ((i < sLen - 1 && s[i] === 'b' && s[i + 1] === 'a')
            || (i > 0 && s[i] === 'a' && s[i - 1] === 'b'))
        {
            return false;
        }
    }
    
    return true;
};