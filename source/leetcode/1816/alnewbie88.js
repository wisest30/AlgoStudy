/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var truncateSentence = function(s, k) {
    let words = s.split(' ');
    let output = '';
    for (let i = 0; i < k; i++) {
        output += words[i] + ' ';
    }
    
    return output.substring(0, output.length - 1);
};