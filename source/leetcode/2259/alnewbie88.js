/**
 * @param {string} number
 * @param {character} digit
 * @return {string}
 */
var removeDigit = function(number, digit) {
    let maxNumStr = 0;
    for (let i = 0; i < number.length; i++) {
        if (number[i] === digit) {
            const numStr = number.substring(0, i) + number.substring(i + 1, number.length);
            if (numStr > maxNumStr) {   // lexicographical order
                maxNumStr = numStr;
            }
        }
    }
    
    return maxNumStr;
};