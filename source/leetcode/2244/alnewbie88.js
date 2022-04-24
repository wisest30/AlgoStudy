/**
 * @param {number[]} queries
 * @param {number} intLength
 * @return {number[]}
 */
var kthPalindrome = function(queries, intLength) {
    let makePalindrome = function(intLength, query) {
        let maxQuery = 9 * Math.pow(10, Math.floor((intLength - 1) / 2));
        if (query > maxQuery) {
            return -1;
        }
        
        if (intLength === 1) {
            return query;
        }
        
        let maxQueryDigits = 0;
        while (maxQuery > 0) {
            maxQuery = Math.floor(maxQuery / 10);
            maxQueryDigits++;
        }
        
        let leftNum = query;
        if (maxQueryDigits >= 2) {
            leftNum += parseInt(''.padStart(maxQueryDigits - 1, '9'));
        }
        leftNum = leftNum.toString();
        
        let palindrome = '';
        if (intLength % 2 === 1) {
            const leftNumWithoutLast = leftNum.slice(0, leftNum.length - 1);
            palindrome = leftNum + leftNumWithoutLast.split('').reverse().join('');
        } else {
            palindrome = leftNum + leftNum.split('').reverse().join('');
        }
        return parseInt(palindrome);
    }
    
    let ans = [];
    queries.forEach(query => ans.push(makePalindrome(intLength, query)));
    return ans;
};