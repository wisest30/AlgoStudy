/**
 * @param {string[]} startWords
 * @param {string[]} targetWords
 * @return {number}
 */
var wordCount = function(startWords, targetWords) {
    const charCode_a = 'a'.charCodeAt(0);
    let wordToBitmask = function(word) {
        let bitmask = 0;
        for (let i = 0; i < word.length; i++) {
            const idx = word[i].charCodeAt(0) - charCode_a;
            bitmask |= 1 << idx;
        }
        return bitmask;
    }
    
    let startWordsBitmaskSet = new Set();
    for (let i = 0; i < startWords.length; i++) {
        const word = startWords[i];
        startWordsBitmaskSet.add(wordToBitmask(word));
    }
    
    let cnt = 0;
    for (let i = 0; i < targetWords.length; i++) {
        const word = targetWords[i];
        if (word.length === 1) {
            continue;
        }
        
        let bitmask = wordToBitmask(word);
        for (let j = 0; j < word.length; j++) {
            let bitmaskWithoutOneLetter = bitmask - (1 << word[j].charCodeAt(0) - charCode_a);
            if (startWordsBitmaskSet.has(bitmaskWithoutOneLetter)) {
                cnt++;
                break;
            }
        }
    }
    
    return cnt;
};
