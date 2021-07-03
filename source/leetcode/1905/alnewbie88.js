/**
 * @param {number[][]} grid1
 * @param {number[][]} grid2
 * @return {number}
 */
var countSubIslands = function(grid1, grid2) {
    const m = grid1.length;
    const n = grid1[0].length;
    
    var checkGrid1ContainIslandStartFrom = function(cellIdx) {
        let res = true;
        let stack = [];
        stack.push(cellIdx);
        while(stack.length > 0) {
            let idx = stack.pop();
            let i = Math.floor(idx / n);
            let j = idx % n;
            if (grid2[i][j] === 0 || grid2[i][j] === 2) {
                continue;
            }
            
            if (grid1[i][j] !== grid2[i][j]) {
                res = false;
            }
            
            grid2[i][j] = 2;    // visited
            
            if (i - 1 >= 0 && grid2[i - 1][j] === 1) {   // up
                stack.push((i - 1) * n + j);
            }
            if (j + 1 < n && grid2[i][j + 1] === 1) {   // right
                stack.push(i * n + j + 1);
            }
            if (i + 1 < m && grid2[i + 1][j] === 1) {   // down
                stack.push((i + 1) * n + j);
            }
            if (j - 1 >= 0 && grid2[i][j - 1] === 1) {   // left
                stack.push(i * n + j - 1);
            }
        }
        
        return res;
    }
    
    let subIslands = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid2[i][j] === 1) {
                if (checkGrid1ContainIslandStartFrom(i * n + j)) {
                    subIslands++;
                }
            }
        }
    }
    
    return subIslands;
};