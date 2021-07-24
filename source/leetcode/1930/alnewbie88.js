/**
 * @param {string} s
 * @return {number}
 */
var countPalindromicSubsequence = function(s) {
    let alphabetToIndexes = {}; // ex> s === "bbcbaba" : {"b":[0,1,3,5],"c":[2],"a":[4,6]}
    for (let i = 0; i < s.length; i++) {
        if (!alphabetToIndexes[s[i]]) {
            alphabetToIndexes[s[i]] = [];
            alphabetToIndexes[s[i]].push(i);
        } else {
            alphabetToIndexes[s[i]].push(i);
        }
    }
    
    let alphabets = 'abcdefghijklmnopqrstuvwxyz';
    let AAAs = [];  // len : 26
    let ABAs = [];  // len : 26 * 25 = 650
    for (let i = 0; i < alphabets.length; i++) {
        for (let j = 0; j < alphabets.length; j++) {
            if (i === j) {
                continue;   // without AAA
            }
            ABAs.push(alphabets[i] + alphabets[j] + alphabets[i]);
        }
        AAAs.push(alphabets[i] + alphabets[i] + alphabets[i]);
    }
    
    let ret = 0;
    for (const aaa of AAAs) {
        let a = aaa[0];
        if (alphabetToIndexes[a] && alphabetToIndexes[a].length >= 3) {
            ret++;
        }
    }
    
    for (const aba of ABAs) {
        if (!alphabetToIndexes[aba[0]] || alphabetToIndexes[aba[0]].length < 2) {
            continue;
        }
        if (!alphabetToIndexes[aba[1]] || alphabetToIndexes[aba[1]].length === 0) {
            continue;
        }
        
        let firstIdxOfA = alphabetToIndexes[aba[0]][0];
        let lastIdxOfA = alphabetToIndexes[aba[0]][alphabetToIndexes[aba[0]].length - 1];
        for (const idx of alphabetToIndexes[aba[1]]) {    // todo : replace to binary search
            if (idx > firstIdxOfA && idx < lastIdxOfA) {
                ret++;
                break;
            }
        }
    }
    
    return ret;
};