/**
 * @param {string} s
 * @return {number}
 */
var countHomogenous = function(s) {
    let homogenousStrs = [];
    let startIdx = 0;
    for (let i = startIdx; i < s.length; i++) {
        if (s[i] !== s[i + 1] || i === s.length - 1) {
            homogenousStrs.push(s.substring(startIdx, i + 1));
            startIdx = i + 1;
        }
    }
    
    let modForLargeNum = Math.pow(10, 9) + 7;
    let count = 0;
    homogenousStrs.forEach(str => {
        let strlen = str.length;
        if (strlen % 2 === 0) {
            count += ((strlen + 1) * (strlen / 2)) % modForLargeNum;
        } else {
            count += (((strlen + 1) * Math.floor(strlen / 2)) + Math.ceil(strlen / 2)) % modForLargeNum;
        }
    });
    
    return count;
};