/**
 * @param {number[]} digits
 * @return {number[]}
 */
var findEvenNumbers = function(digits) {
    const n = digits.length;
    let nums = new Set();
    for (let i = 0; i < n; i++) {
        if (digits[i] === 0) {
            continue;
        }
        for (let j = 0; j < n; j++) {
            if (i === j) {
                continue;
            }
            for (let k = 0; k < n; k++) {
                if (k === i || k === j) {
                    continue;
                }
                
                const num = (digits[i] * 100) + (digits[j] * 10) + digits[k];
                if (num % 2 === 0) {
                    nums.add(num);
                }
            }
        }
    }
    
    let sortedNums = [...nums].sort(function(a, b) { return a - b; });
    return sortedNums;
};
