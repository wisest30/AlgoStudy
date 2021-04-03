/**
 * @param {number} n
 * @param {number} index
 * @param {number} maxSum
 * @return {number}
 */
var maxValue = function(n, index, maxSum) {
    var calcSum = function(val, len) {
        /*// Maximum call stack size exceeded
        if (val === 0) val = 1;
        if (len === 0) return 0;
        return val + calcSum(val - 1, len - 1);
        */
        let sum = 0;
        if (len <= val) {
            sum = (2 * val - len + 1) * len / 2;
        } else {
            sum = (1 + val) * (val / 2) + len - val;
        }
        return sum;
    }
    
    var check = function(value) {
        let leftSum = calcSum(value - 1, index);
        let rightSum = calcSum(value - 1, n - index - 1);
        return value + leftSum + rightSum;
    }
    
    let l = 0;
    let r = maxSum;
    let m;
    while (l < r) {
        m = Math.ceil((l + r + 1) / 2);
        let sum = check(m);
        if (sum <= maxSum) {
            l = m;
        }
        else
            r = m - 1;
    }
    return l;
};