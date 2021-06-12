/**
 * @param {string} firstWord
 * @param {string} secondWord
 * @param {string} targetWord
 * @return {boolean}
 */
var isSumEqual = function(firstWord, secondWord, targetWord) {
    const aCharCode = "a".charCodeAt(0);
    var wordToNumber = function(word) {
        let strNumber = "";
        for (let i = 0; i < word.length; i++) {
            strNumber += (word.charCodeAt(i) - aCharCode).toString();
        }
        return Number(strNumber);
    }
    
    return wordToNumber(firstWord) + wordToNumber(secondWord) === wordToNumber(targetWord); 
};