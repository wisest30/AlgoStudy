/**
 * @param {number} n
 * @return {number}
 */
var countHousePlacements = function(n) {
    const modulo = BigInt(1e9 + 7);
    let memo = new Array(10001).fill(0);
    let fiboLike = function(n) {
        if (n === 1) return 2;
        if (n === 2) return 3;
        if (memo[n] > 0) return memo[n];
        
        memo[n] = BigInt(fiboLike(n - 1)) + BigInt(fiboLike(n - 2));
        return memo[n] % modulo;
    }
    
    let oneSideWaysCount = BigInt(fiboLike(n));
    return (oneSideWaysCount * oneSideWaysCount) % modulo;
};