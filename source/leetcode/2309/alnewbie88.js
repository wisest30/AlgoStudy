/**
 * @param {string} s
 * @return {string}
 */
var greatestLetter = function(s) {
    const chCode_a = 'a'.charCodeAt(0);
    const chCode_A = 'A'.charCodeAt(0);
    let lowerExists = new Array(26).fill(false);
    let upperExists = new Array(26).fill(false);
    for (let i = 0; i < s.length; i++) {
        const ch = s[i];
        const chCode = ch.charCodeAt(0);
        const isLower = ch === ch.toLowerCase();
        if (isLower) {
            lowerExists[chCode - chCode_a] = true;
        } else {
            upperExists[chCode - chCode_A] = true;
        }
    }
    
    for (let i = 25; i >= 0; i--) {
        if (lowerExists[i] && upperExists[i]) {
            return String.fromCharCode(chCode_A + i);
        }
    }
    
    return '';
};