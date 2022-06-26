/**
 * @param {number} num
 * @param {number} k
 * @return {number}
 */
var minimumNumbers = function(num, k) {
    if (num === 0) {
        return 0;
    }
	
    for (let n = 1; n <= 10; n++) {
        if (n * k <= num && (n * k % 10 == num % 10)) {
            return n;
        }
    }
    
    return -1;
};