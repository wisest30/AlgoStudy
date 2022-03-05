/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var minSteps = function(s, t) {
    let sArr = new Array(26).fill(0);
    let tArr = new Array(26).fill(0);
    
    const aCharCode = 'a'.charCodeAt(0);
    for (let i = 0; i < s.length; i++) {
        const chCode = s.charCodeAt(i) - aCharCode;
        sArr[chCode]++;
    }
    for (let i = 0; i < t.length; i++) {
        const chCode = t.charCodeAt(i) - aCharCode;
        tArr[chCode]++;
    }
    
    let sameCharCount = 0;
    for (let i = 0 ; i < 26; i++) {
        sameCharCount += Math.min(sArr[i], tArr[i]);
    }
    
    return (s.length - sameCharCount) + (t.length - sameCharCount);
};
