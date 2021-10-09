/**
 * @param {number[]} stones
 * @return {boolean}
 */
var stoneGameIX = function(stones) {
    let stonesModBy3 = new Array(3).fill(0);
    stones.forEach(s => stonesModBy3[s % 3]++);
    if (Math.min(stonesModBy3[1], stonesModBy3[2]) === 0) {
        return Math.max(stonesModBy3[1], stonesModBy3[2]) >= 3 && stonesModBy3[0] % 2 === 1;
    }
    
    return stonesModBy3[0] % 2 === 0 || Math.abs(stonesModBy3[1] - stonesModBy3[2]) >= 3;
};