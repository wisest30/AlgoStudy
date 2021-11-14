/**
 * @param {string} word
 * @return {number}
 */
var countVowels = function(word) {
    const wordLen = word.length;
    let cnt = 0;
    for (let i = 0; i < wordLen; i++) {
        if ('aeiou'.indexOf(word[i]) !== -1) {
            cnt += (i + 1) * (wordLen - i);
        }
    }
    
    return cnt;
};