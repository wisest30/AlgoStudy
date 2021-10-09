/**
 * @param {number[]} rolls
 * @param {number} mean
 * @param {number} n
 * @return {number[]}
 */
var missingRolls = function(rolls, mean, n) {
    const m = rolls.length;
    const totalSum = mean * (m + n);
    const mSum = rolls.reduce((accum, curVal) => accum + curVal, 0);
    const nSum = totalSum - mSum;
    if (nSum < n || nSum > n * 6) {
        return [];
    }
    
    // 모든 요소에 최소값 1을 셋업해두고, 앞에서부터 최대수 6으로 채우기
    const sixValRollCnt = Math.floor((nSum - n) / 5);
    const remainedVal = (nSum - n) % 5;
    let result = [];
    for (let i = 0; i < n; i++) {
        if (i < sixValRollCnt) {
            result.push(6);
        } else if (i === sixValRollCnt && remainedVal > 0) {
            result.push(1 + remainedVal);
        } else {
            result.push(1);
        }
    }
    
    return result;
};