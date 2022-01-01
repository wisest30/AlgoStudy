/**
 * @param {number} num
 * @return {boolean}
 */
var isSameAfterReversals = function(num) {
    let strNum = num.toString();
    let reverse1 = strNum.split('').reverse().join('');
    let reverse2 = Number(reverse1).toString().split('').reverse().join('');
    return num === Number(reverse2);
};
