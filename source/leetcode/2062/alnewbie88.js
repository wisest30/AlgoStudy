function getAllSubstrings(str) {
    let result = [];
    for (let i = 0; i < str.length; i++) {
        for (let j = i; j < str.length; j++) {
            result.push(str.slice(i, j + 1));
        }
    }
    return result;
}

/**
 * @param {string} word
 * @return {number}
 */
var countVowelSubstrings = function(word) {
    if (word.length < 5) {
        return 0;
    }
    
    let vowelExists = new Map();
    var checkAllWordIsVowel = function(str) {
        vowelExists.clear();
        for (let i = 0; i < str.length; i++) {
            if ('aeiou'.indexOf(str[i]) === -1) {
                return false;
            }
            vowelExists.set(str[i], true);
        }
        return true;
    }
    
    let resultCnt = 0;
    const subStrings = getAllSubstrings(word);
    subStrings.forEach(str => {
        if (checkAllWordIsVowel(str) && vowelExists.size === 5) {
            resultCnt++;
        }
    });
    
    return resultCnt;
};