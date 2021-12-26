/**
 * @param {string[]} words
 * @return {string}
 */
var firstPalindrome = function(words) {
    for (let i = 0; i < words.length; i++) {
        const word = words[i];
        const wordLen = word.length;
        let isPalendrome = true;
        for (let j = 0; j < Math.floor(wordLen / 2); j++) {
            if (word[j] !== word[wordLen - 1 - j]) {
                isPalendrome = false;
                break;
            }
        }
        if (isPalendrome) {
            return word;
        }
    }
    
    return "";
};