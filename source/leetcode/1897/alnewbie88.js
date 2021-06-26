/**
 * @param {string[]} words
 * @return {boolean}
 */
var makeEqual = function(words) {
    if (words.length === 1) {
        return true;
    }
    
    let chCount = {};
    for (let i = 0; i < words.length; i++) {
        for (const ch of words[i]) {
            if (!chCount[ch]) {
                chCount[ch] = 1;
            } else {
                chCount[ch]++;
            }
        }
    }
    
    for (const count of Object.values(chCount)) {
        if (count % words.length !== 0) {
            return false;
        }
    }
    
    return true;
};