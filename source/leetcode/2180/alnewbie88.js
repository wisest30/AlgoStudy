/**
 * @param {number} num
 * @return {number}
 */
var countEven = function(num) {
    let count = 0
    for (let i = 1; i <= num; i++) {
        const digits = i.toString().split('');
        const digitSum = digits.reduce((accum, curVal) => accum + Number(curVal), 0);
        if (digitSum % 2 === 0) {
            count++;
        }
    }
    
    return count;
};