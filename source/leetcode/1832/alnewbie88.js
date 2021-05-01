/**
 * @param {string} sentence
 * @return {boolean}
 */
var checkIfPangram = function(sentence) {
    let charCode_a = 'a'.charCodeAt(0); // 97
    let arrLen = 'z'.charCodeAt(0) - 'a'.charCodeAt(0) + 1;
    let arr = new Array(arrLen).fill(false);
    for (const ch of sentence) {
        arr[ch.charCodeAt(0) - charCode_a] = true;
    }
    
    for (const elem of arr) {
        if (!elem) {
            return false;
        }
    }
    
    return true;
};