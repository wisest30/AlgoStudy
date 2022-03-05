/**
 * @param {string[]} words
 * @param {string} pref
 * @return {number}
 */
var prefixCount = function(words, pref) {
    let count = 0;
    words.forEach(word => {
        if (word.indexOf(pref) === 0) {
            count++;
        }
    });
    
    return count;
};