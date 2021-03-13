/**
 * @param {number[]} baseCosts
 * @param {number[]} toppingCosts
 * @param {number} target
 * @return {number}
 */
var closestCost = function(baseCosts, toppingCosts, target) {
    var makeToppingSubSequences = function(arr, index, subArr) {
        if (index === arr.length) {
            if (subArr.length > 0) {
                toppingSubSeqs.push(subArr);
            }
            return;
        }
        
        makeToppingSubSequences(arr, index + 1, subArr.slice(0));
        
        subArr.push(arr[index]);
        makeToppingSubSequences(arr, index + 1, subArr.slice(0));
    }
    
    var makeToppingCostSums = function(arr, index, sum, outSums) {
        if (index === arr.length) {
            outSums.push(sum);
            return;
        }

        makeToppingCostSums(arr, index + 1, sum + arr[index], outSums);          // case for one topping
        makeToppingCostSums(arr, index + 1, sum + (arr[index] * 2), outSums);    // case for two topping
    }
    
    let toppingSubSeqs = [];
    makeToppingSubSequences(toppingCosts, 0, new Array());
    
    let minCostDiffToTarget = Number.MAX_SAFE_INTEGER;
    let closestCost = 0;
    for (let i = 0; i < baseCosts.length; i++) {
        for (let j = 0; j < toppingSubSeqs.length; j++) {
            let totalToppingCosts = [];
            makeToppingCostSums(toppingSubSeqs[j], 0, 0, totalToppingCosts);
            totalToppingCosts.push(0);  // no topping

            for (let k = 0; k < totalToppingCosts.length; k++) {
                let cost = baseCosts[i] + totalToppingCosts[k];
                let diff = Math.abs(target - cost);
                if (diff < minCostDiffToTarget || (diff === minCostDiffToTarget && target - cost > 0)) {
                    minCostDiffToTarget = diff;
                    closestCost = cost;
                }
            }
        }
    }
    
    return closestCost;
};