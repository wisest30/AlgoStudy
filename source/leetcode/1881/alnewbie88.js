/**
 * @param {string} n
 * @param {number} x
 * @return {string}
 */
var maxValue = function(n, x) {
    let nIsNegative = Number(n) < 0;
    if (nIsNegative) {
        n = n.slice(1); // remove '-'
    }
    
    let insertIdx = -1;
    for (let i = 0; i < n.length; i++) {
        let numberN = Number(n[i]);
        if ((nIsNegative && numberN > x) || (!nIsNegative && numberN < x)) {
            insertIdx = i;
            break;
        }
    }    
    if (insertIdx === -1) {
        insertIdx = n.length;
    }
    
    return (nIsNegative ? "-" : "") + n.slice(0, insertIdx) + x.toString() + n.slice(insertIdx);
};