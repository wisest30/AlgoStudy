/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var checkValid = function(matrix) {
    const n = matrix.length;
    for (let i = 0; i < n; i++) {
        let row = new Array(n+1).fill(false);
        for (let j = 0; j < n; j++) {
            if (row[matrix[i][j]]) {
                return false;   // if has duplicate number, invalid
            }
            row[matrix[i][j]] = true;
        }
        
        let col = new Array(n+1).fill(false);
        for (let j = 0; j < n; j++) {
            if (col[matrix[j][i]]) {
                return false;   // if has duplicate number, invalid
            }
            col[matrix[j][i]] = true;
        }
    }
    
    return true;
};