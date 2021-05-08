/**
 * @param {string} word
 * @return {number}
 */
var longestBeautifulSubstring = function(word) {
    const wordLen = word.length;
    let arrVowels = new Array(5).fill(false);
    var setHasVowel = function(ch) {
        switch(ch) {
            case 'a': arrVowels[0] = true; break;
            case 'i': arrVowels[2] = true; break;
            case 'e': arrVowels[1] = true; break;
            case 'o': arrVowels[3] = true; break;
            case 'u': arrVowels[4] = true; break;
        }
    }
    
    let longest = 0;
    let startIdx = 0;
    let endIdx = startIdx + 1;
    setHasVowel(word[startIdx]);
    
    let state = undefined;  // 0 : beautiful, 1 : has not aeiou, 2 : unsorted
    while (startIdx < wordLen && endIdx < wordLen) {
        state = 0;
        if (word.charCodeAt(endIdx) - word.charCodeAt(endIdx - 1) < 0) {    // check sorted
            state = 2;
        }
        else {  // check has aeiou
            setHasVowel(word[endIdx]);
            for (const vowel of arrVowels) {
                if (vowel !== true) {
                    state = 1;
                    break;
                }
            }
        }
        
        //console.log('substring=' + word.substring(startIdx, endIdx + 1) + ', state=' + state);
        switch (state) {
            case 0:
                let subStringLen = endIdx - startIdx + 1;
                if (subStringLen > longest) {
                    longest = subStringLen;
                }
                endIdx++;
                break;
            case 1:
                endIdx++;
                break;
            case 2:
                startIdx = endIdx;
                endIdx = startIdx + 1;
                arrVowels.fill(false);
                setHasVowel(word[startIdx]);
                break;
        }
    }
    
    return longest;
};