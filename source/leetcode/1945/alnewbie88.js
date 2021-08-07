/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLucky = function(s, k) {
    let charCode_a = "a".charCodeAt(0);
    let transformStr = '';
    for (let i = 0; i < s.length; i++) {
        let alphabetCode = s.charCodeAt(i) - charCode_a + 1;
        transformStr += alphabetCode.toString();
    }
    
    let ret = 0;
    for (let i = 0; i < k; i++) {
        ret = 0;
        for (const chNum of transformStr) {
            ret += Number(chNum);
        }
        transformStr = ret.toString();
    }
    
    return ret;
};