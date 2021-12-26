/**
 * @param {number[]} prices
 * @return {number}
 */
var getDescentPeriods = function(prices) {
    let memo = new Array(100001).fill(-1);
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
    var recur = function(n) {
        if (memo[n] > -1) {
            return memo[n];
        }
        
        memo[n] = recur(n - 1) + (n - 1);
        return memo[n];
    };
    
    for (let i = 1; i <= 100000; i++) {
        recur(i);
    }
    
    let answer = prices.length; // one elements
    let contiguosStartIdx = 0;
    for (let i = 1; i < prices.length; i++) {
        const isSmoothDescent = prices[i] - prices[i - 1] === -1;
        if (isSmoothDescent) {
            const isLastElem = i === prices.length - 1;
            if (isLastElem) {
                const contiguosLen = i + 1 - contiguosStartIdx;
                if (contiguosLen >= 2) {
                    answer += memo[contiguosLen];
                }
            }
        } else {
            const contiguosLen = i - contiguosStartIdx;
            if (contiguosLen >= 2) {
                answer += memo[contiguosLen];
            }
            contiguosStartIdx = i;
        }
    }
    
    return answer;
}
