function minOperations(grid: number[][], x: number): number {
    let m = new Map<number, number>();
    let moduloByX = grid[0][0] % x;
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            if (grid[i][j] % x !== moduloByX) {
                return -1;  // impossible make all elems to equal.
            }
            
            const q = (grid[i][j] - moduloByX) / x;
            if (m.has(q)) {
                m.set(q, m.get(q) + 1);
            } else {
                m.set(q, 1);
            }
        } 
    }
    
    let minOperations = Number.MAX_SAFE_INTEGER;
    for (const q of m.keys()) {
        let totalOperations = 0;
        for (const [key, value] of m.entries()) {
            const numOperations = Math.abs(key - q) * value;
            totalOperations += numOperations;
        }
        minOperations = Math.min(minOperations, totalOperations);
    }
    
    return minOperations;
};