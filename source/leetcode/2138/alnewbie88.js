/**
 * @param {string} s
 * @param {number} k
 * @param {character} fill
 * @return {string[]}
 */
var divideString = function(s, k, fill) {
    let ret = [];
    for (let i = 0; i < s.length; i += k) {
        if (i + k >= s.length) {
            let fillCnt = k - (s.length - i);
            let padding = '';
            for (let j = 0; j < fillCnt; j++) {
                padding += fill;
            }
            ret.push(s.substring(i, s.length) + padding);
        } else {
            ret.push(s.substring(i, i + k));
        }
    }
    
    return ret;
};