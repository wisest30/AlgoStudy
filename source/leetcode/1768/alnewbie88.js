/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    let i = 0;
    let merged = "";
    for (; i < word1.length; i++) {
        if (i >= word2.length) {
            merged += word1.substring(i, word1.length);
            break;
        }
        merged += word1[i] + word2[i];
    }
    
    if (i < word2.length) {
        merged += word2.substring(i, word2.length);
    }
    
    return merged;
};