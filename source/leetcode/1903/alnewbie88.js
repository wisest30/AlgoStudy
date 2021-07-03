/**
 * @param {string} num
 * @return {string}
 */
var largestOddNumber = function(num) {
    for (let i = num.length - 1; i >= 0; i--) {
        let isOdd = Number.parseInt(num[i]) % 2 > 0;
        if (!isOdd) {
            continue;
        }
        return num.substring(0, i + 1);
    }
    
    return "";
};