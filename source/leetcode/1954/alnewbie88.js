/**
 * @param {number} neededApples
 * @return {number}
 */
var minimumPerimeter = function(neededApples) {
    let rToApples = {};
    rToApples[0] = 0;
    rToApples[1] = 12;
    
    const maxRadius = 100000;   // rToApples[100000] == 4000060000200000 (> 10^15)
    for (let r = 2; r <= maxRadius; r++) {
        rToApples[r] = rToApples[r - 1] + (rToApples[r - 1] - rToApples[r - 2] + 12 + (24 * (r - 1)));
    }
    
    for (let r = 1; r <= maxRadius; r++) {
        if (rToApples[r] >= neededApples) {
            return r * 8;
        }
    }
    
    return 0;   // error!
};