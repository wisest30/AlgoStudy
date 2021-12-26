/**
 * @param {string} s
 * @param {number[]} spaces
 * @return {string}
 */
var addSpaces = function(s, spaces) {
    let spaceIdx = 0;
    let result = "";
    for (let i = 0; i < s.length; i++) {
        if (spaceIdx >= 0 && spaceIdx < spaces.length && i === spaces[spaceIdx]) {
            result += ' ';
            spaceIdx++;
        }
        
        result += s[i];
    }
    
    return result;
};