/**
 * @param {string} num
 * @param {number[]} change
 * @return {string}
 */
var maximumNumber = function(num, change) {
    let mutating = false;
    for (let i = 0; i < num.length; i++) {
        let newNum = num.substring(0, i) + change[num[i]] + num.substring(i + 1);
        if (mutating) {
            if (change[num[i]] < num[i]) {
                break;
            } else {
                num = newNum;
            }
        } else {
            if (change[num[i]] > num[i]) {
                num = newNum;
                mutating = true;
            }
        }
    }
    
    return num;
};