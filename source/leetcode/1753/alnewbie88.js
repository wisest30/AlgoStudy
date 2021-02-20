/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var maximumScore = function(a, b, c) {
    let arr = [a, b, c];
    let score = 0;
    while(true) {
        // sort desc
        arr.sort(function(a, b) {
            return b - a;
        });
        
        let upperZeroNums = 0;
        for (let i = 0; i < arr.length; i++) {
            if (arr[i] > 0) {
                upperZeroNums++;
            }
        }
        
        if (upperZeroNums < 2) {
            break;
        } else {
            arr[0]--;
            arr[1]--;
            score++;
        }
    }
    
    return score;
};