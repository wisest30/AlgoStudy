/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var largestMerge = function(word1, word2) {
    var ret = "";
    while(word1.length > 0 && word2.length > 0) {
        if (word1 > word2) {
            ret += word1[0];
            word1 = word1.substring(1, word1.length);
        } else {
            ret += word2[0];
            word2 = word2.substring(1, word2.length);
        }
    }
    
    ret += word1;
    ret += word2;
    return ret;
};