/**
 * @param {string} s
 * @return {number}
 */
var minOperations = function(s) {
    let zeroOne = "";
    let oneZero = "";
    for (let i = 0; i < s.length; i++) {
        if (i % 2 === 0) {
            zeroOne += '0';
            oneZero += '1';
        } else {
            zeroOne += '1';
            oneZero += '0';
        }
    }
    
    let diffChCountFromZeroOne = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] !== zeroOne[i]) {
            diffChCountFromZeroOne++
        }
    }
    
    let diffChCountFromOneZero = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] !== oneZero[i]) {
            diffChCountFromOneZero++
        }
    }
    
    return diffChCountFromZeroOne <= diffChCountFromOneZero ? diffChCountFromZeroOne : diffChCountFromOneZero;
};