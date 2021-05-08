/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var sumBase = function(n, k) {
    let arr = [];
    let q = n;  // quotient
    do {
        arr.push(q % k);
        q = Math.floor(q / k);
    } while (q >= k);
    
    if (q > 0) {
        arr.push(q);
    }
    
    return arr.reduce((accum, curVal) => accum + curVal, 0);
};