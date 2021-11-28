function binarySearch(array, pred) {
    let l = 0;
    let r = array.length;
    while (l < r) {
        const m = Math.floor((l + r) / 2);
        if (pred(array[m])) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return r;
}

function lowerBound(array, item) { return binarySearch(array, j => item <= j); }
function upperBound(array, item) { return binarySearch(array, j => item < j); }

let hasValueIndexes;

/**
 * @param {number[]} arr
 */
var RangeFreqQuery = function(arr) {
    hasValueIndexes = new Array(10000 + 1);
    for (let i = 0; i < hasValueIndexes.length; i++) {
        hasValueIndexes[i] = new Array();
    }
    
    for (let i = 0; i < arr.length; i++) {
        hasValueIndexes[arr[i]].push(i);
    }
};

/** 
 * @param {number} left 
 * @param {number} right 
 * @param {number} value
 * @return {number}
 */
RangeFreqQuery.prototype.query = function(left, right, value) {
    return upperBound(hasValueIndexes[value], right) - lowerBound(hasValueIndexes[value], left);
};

/** 
 * Your RangeFreqQuery object will be instantiated and called as such:
 * var obj = new RangeFreqQuery(arr)
 * var param_1 = obj.query(left,right,value)
 */