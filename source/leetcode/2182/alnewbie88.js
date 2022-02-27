/**
 * @param {string} s
 * @param {number} repeatLimit
 * @return {string}
 */
var repeatLimitedString = function(s, repeatLimit) {
    let findSwapTargetIdx = function(arr, idx) {
        for (let i = idx + 1; i < arr.length; i++) {
            if (arr[idx] !== arr[i]) {
                return i;
            }
        }
        return -1;
    }
    
    let arr = s.split('').sort().reverse();
    
    let repeatCnt = 0;
    let swapTargetIdx = -1;
    let prevChar = '';
    for (let i = 0; i < arr.length; i++) {
        if (swapTargetIdx === -1 || arr[i] !== prevChar) {
            swapTargetIdx = findSwapTargetIdx(arr, i);
            if (swapTargetIdx === -1) {
                arr = arr.slice(0, Math.min(i + repeatLimit, arr.length));
                break;
            }
            repeatCnt = 0;
        }
        
        prevChar = arr[i];
        if (++repeatCnt > repeatLimit) {
            if (swapTargetIdx >= arr.length) {
                arr = arr.slice(0, i);
                break;
            }
            
            // swap
            const temp = arr[i];
            arr[i] = arr[swapTargetIdx];
            arr[swapTargetIdx] = temp;
            repeatCnt = 0;
            swapTargetIdx++;
        }
    }
    
    return arr.join('');
};