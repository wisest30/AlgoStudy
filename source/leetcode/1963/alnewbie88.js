/**
 * @param {string} s
 * @return {number}
 */
var minSwaps = function(s) {
    let stack = [];
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '[') {
            stack.push(s[i]);
        } else if (stack.length > 0) {
            stack.pop();
        }
    }
    
    return Math.floor((stack.length + 1) / 2);
};