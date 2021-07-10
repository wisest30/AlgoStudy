/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number[][]}
 */
var rotateGrid = function(grid, k) {
    const m = grid.length;
    const n = grid[0].length;
    
    let rotTable = new Array(m);
    let num = 0;
    for (let i = 0; i < m; i++) {
        rotTable[i] = new Array(n);
        for (let j = 0; j < n; j++) {
            rotTable[i][j] = num++;
        }
    }
    
    let numlayers = Math.min(m / 2, n / 2);
    for (let layerIdx = 0; layerIdx < numlayers; layerIdx++) {
        for (let j = layerIdx; j < n - 1 - layerIdx; j++) {
            rotTable[layerIdx][j] += 1;
        }
        for (let i = layerIdx + 1; i < m - layerIdx; i++) {
            rotTable[i][layerIdx] -= n;
        }
        for (let j = layerIdx + 1; j < n - layerIdx; j++) {
            rotTable[m - 1 - layerIdx][j] -= 1;
        }
        for (let i = layerIdx; i < m - 1 - layerIdx; i++) {
            rotTable[i][n - 1 - layerIdx] += n;
        }
    }
    
    var cyclicallyRotate = function(g, layerIdx) {
        let copied_g = JSON.parse(JSON.stringify(g));
        for (let j = layerIdx; j < n - 1 - layerIdx; j++) {
            let idx = rotTable[layerIdx][j];
            let org_i = Math.floor(idx / n);
            let org_j = idx % n;
            g[layerIdx][j] = copied_g[org_i][org_j];
        }
        for (let i = layerIdx + 1; i < m - layerIdx; i++) {
            let idx = rotTable[i][layerIdx];
            let org_i = Math.floor(idx / n);
            let org_j = idx % n;
            g[i][layerIdx] = copied_g[org_i][org_j];
        }
        for (let j = layerIdx + 1; j < n - layerIdx; j++) {
            let idx = rotTable[m - 1 - layerIdx][j];
            let org_i = Math.floor(idx / n);
            let org_j = idx % n;
            g[m - 1 - layerIdx][j] = copied_g[org_i][org_j];
        }
        for (let i = layerIdx; i < m - 1 - layerIdx; i++) {
            let idx = rotTable[i][n - 1 - layerIdx];
            let org_i = Math.floor(idx / n);
            let org_j = idx % n;
            g[i][n - 1 - layerIdx] = copied_g[org_i][org_j];
        }
    }
    
    for (let layerIdx = 0; layerIdx < numlayers; layerIdx++) {
        let numRotations = k % ((m - 1 - (layerIdx * 2)) * 2 + (n - 1 - (layerIdx * 2)) * 2);
        for (let i = 0; i < numRotations; i++) {
            cyclicallyRotate(grid, layerIdx);
        }
    }
    
    return grid;
};