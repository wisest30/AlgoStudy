/**
 * @param {string} boxes
 * @return {number[]}
 */
var minOperations = function(boxes) {
    let boxesInt = [];
    [...boxes].forEach(val => boxesInt.push(val));
    
    let len = boxes.length;
    let result = new Array(len).fill(0);
    for (let i = 0; i < len; i++) {
        for (let j = 0; j < len; j++) {
            if (i === j || boxesInt[j] === '0') {
                continue;
            }
            result[i] += Math.abs(j-i);
        }
    }
    
    return result;
};