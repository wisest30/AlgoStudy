let drawCircle = function(grid, x, y, r) {
    for (let x2 = x - r; x2 <= x + r; x2++) {
        for (let y2 = y - r; y2 <= y + r; y2++) {
            const xDiff = Math.abs(x2 - x);
            const yDiff = Math.abs(y2 - y);
            let distSqrt = xDiff * xDiff + yDiff * yDiff;
            if (distSqrt <= r * r) {
                grid[x2][y2] = 1;
            }
        }
    }
}

/**
 * @param {number[][]} circles
 * @return {number}
 */
var countLatticePoints = function(circles) {
    const maxX = 201;   // x + r <= 200
    const maxY = 201;   // y + r <= 200
    let grid = new Array(maxX).fill(0);
    for (let i = 0; i < maxX; i++) {
        grid[i] = new Array(maxY).fill(0);
    }
    
    circles.forEach(circle => drawCircle(grid, circle[0], circle[1], circle[2]));
    
    let cnt = 0;
    for (let i = 0; i < maxX; i++) {
        for (let j = 0; j < maxY; j++) {
            if (grid[i][j] > 0) {
                cnt++;
            }
        }
    }
    
    return cnt;
};