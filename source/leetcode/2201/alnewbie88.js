function isPossibleExtract(grid, r1, c1, r2, c2) {
    for (let r = r1; r <= r2; r++) {
        for (let c = c1; c <= c2; c++) {
            if (grid[r][c] === 0) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @param {number} n
 * @param {number[][]} artifacts
 * @param {number[][]} dig
 * @return {number}
 */
var digArtifacts = function(n, artifacts, dig) {
    let grid = new Array(n);
    for (let i = 0; i < n; i++) {
        grid[i] = new Array(n).fill(0);
    }
    
    dig.forEach(d => { grid[d[0]][d[1]] = 1; });
    
    let extract = 0;
    artifacts.forEach(artifact => {
        if (isPossibleExtract(grid, artifact[0], artifact[1], artifact[2], artifact[3])) {
            extract++;
        }
    });
    
    return extract;
};