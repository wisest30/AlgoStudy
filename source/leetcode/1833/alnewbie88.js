/**
 * @param {number[]} costs
 * @param {number} coins
 * @return {number}
 */
var maxIceCream = function(costs, coins) {
    costs.sort(function(a, b) {
        return b - a;
    });
    
    let numPaid = 0;
    while (coins > 0 && costs.length > 0) {
        if (coins < costs[costs.length - 1])
            break;
        
        coins -= costs[costs.length - 1];
        numPaid++;
        costs.pop();
    }
    
    return numPaid;
};