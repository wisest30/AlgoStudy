/**
 * @param {number[]} arr
 * @return {number[]}
 */
var getDistances = function(arr) {
    const n = arr.length;
    let numToIndexes = new Map();
    for (let i = 0; i < n; i++) {
        const num = arr[i];
        if (numToIndexes.has(num)) {
            numToIndexes.get(num).push(i);
        } else {
            numToIndexes.set(num, [i]);
        }
    }
    
    let answer = new Array(n);
    let lSum = new Array(100001).fill(0);
    let rSum = new Array(100001).fill(0);
    numToIndexes.forEach((value, key) => {
        //console.log(`key=${key}, value=${value}`);
        const indexes = value;
        for (let i = 1; i < indexes.length; i++) {
            const interval = indexes[i] - indexes[i - 1];
            lSum[indexes[i]] = lSum[indexes[i - 1]] + (i * interval);
        }
        
        for (let i = indexes.length - 2; i >= 0; i--) {
            const interval = indexes[i + 1] - indexes[i];
            rSum[indexes[i]] = rSum[indexes[i + 1]] + ((indexes.length - 1 - i) * interval);
        }
        
        for (let i = 0; i < indexes.length; i++) {
            answer[indexes[i]] = lSum[indexes[i]] + rSum[indexes[i]];
        }
    });
    
    return answer;
};
