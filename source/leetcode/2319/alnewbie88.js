/**
 * @param {number[][]} grid
 * @return {boolean}
 */
var checkXMatrix = function(grid) {
    const n = grid.length;
    let x = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            const diagonals = (j === x || j === n - 1 - x);
            const isZero = grid[i][j] === 0;
            if ((diagonals && isZero) || (!diagonals && !isZero)) {
                return false;
            }
        }
        x++;
    }
    
    return true;
};