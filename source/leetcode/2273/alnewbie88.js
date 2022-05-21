/**
 * @param {string[]} words
 * @return {string[]}
 */
var removeAnagrams = function(words) {
    for (let i = 1; i < words.length; i++) {
        let word = words[i].split('').sort().join('');
        let word2 = words[i - 1].split('').sort().join('');
        if (word === word2) {
            words.splice(i, 1);
            i--;
        }
    }
    
    return words;
};