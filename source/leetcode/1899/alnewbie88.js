/**
 * @param {number[][]} triplets
 * @param {number[]} target
 * @return {boolean}
 */
var mergeTriplets = function(triplets, target) {
    let filtered = [];
    for (const triplet of triplets) {
        let sameWithTarget = new Array(3).fill(false);
        for (let i = 0; i < 3; i++) {
            if (triplet[i] === target[i]) {
                sameWithTarget[i] = true;
            }
        }
        
        let needSkip = true;
        for (let i = 0; i < 3; i++) {
            if (sameWithTarget[i]) {
                needSkip = false;
                break;
            }
        }
        if (needSkip) {
            continue;
        }
        
        for (let i = 0; i < 3; i++) {
            if (!sameWithTarget[i] && triplet[i] > target[i]) {
                needSkip = true;
                break;
            }
        }
        if (needSkip) {
            continue;
        }
        
        filtered.push(triplet);
    }
    
    let existSameWithTarget = new Array(3).fill(false);
    for (const triplet of filtered) {
        existSameWithTarget[0] |= triplet[0] === target[0];
        existSameWithTarget[1] |= triplet[1] === target[1];
        existSameWithTarget[2] |= triplet[2] === target[2];
        if (existSameWithTarget[0] && existSameWithTarget[1] && existSameWithTarget[2]) {
            return true;
        }
    }
    
    return false;
};