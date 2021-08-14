/**
 * @param {number} n
 * @return {boolean}
 */
var isThree = function(n) {
    let numDivisors = 0;
    for (let i = 1; i <= n; i++) {
        if (n % i === 0) {
            numDivisors++;
            if (numDivisors > 3) {
                return false;
            }
        }
    }
    
    return numDivisors === 3;
};