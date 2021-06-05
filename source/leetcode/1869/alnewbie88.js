/**
 * @param {string} s
 * @return {boolean}
 */
var checkZeroOnes = function(s) {
    let splited = [];
    let startIdx = 0;
    for (let i = 1; i < s.length; i++) {
        if (s[i] !== s[i - 1]) {
            splited.push(s.slice(startIdx, i));
            startIdx = i;
        }
    }
    splited.push(s.slice(startIdx, s.length + 1));
    
    let longestZeroLen = 0;
    let longestOneLen = 0;
    for (const _s of splited) {
        let isZero = _s[0] === '0';
        if (isZero && _s.length > longestZeroLen) {
            longestZeroLen = _s.length;
        } else if (!isZero && _s.length > longestOneLen) {
            longestOneLen = _s.length;
        }
    }
    
    return longestOneLen > longestZeroLen;
};