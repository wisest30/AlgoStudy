/**
 * @param {string} s
 * @return {string[]}
 */
var cellsInRange = function(s) {
    const startCol = s[0];
    const endCol = s[3];
    const startRow = Number(s[1]);
    const endRow = Number(s[4]);
    const colCharCodeDiff = endCol.charCodeAt(0) - startCol.charCodeAt(0);
    
    let ret = [];
    for (let i = 0; i <= colCharCodeDiff; i++) {
        const col = String.fromCharCode(startCol.charCodeAt(0) + i);
        for (let j = startRow; j <= endRow; j++) {
            const row = j.toString();
            ret.push(col + row);
        }
    }
    
    return ret;
};