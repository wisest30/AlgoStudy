// Wrong Answer!!!
/**
 * @param {number} n
 * @return {number}
 */
var countGoodNumbers = function(n) {
    var powMod = function(x, y, m) {
        if (y === 0) {
            return 1;
        }
        
        if (y % 2 === 0) {
            return powMod((x * x) % m, y / 2, m);
        } else {
            return (x * powMod((x * x) % m, (y - 1) / 2, m)) % m;
        }
    }
    
    let numFive = Math.ceil(n / 2);
    let numFour = n - numFive;
    const mod = 1000000000 + 7;
    return (powMod(5, numFive, mod) * powMod(4, numFour, mod)) % mod;
};