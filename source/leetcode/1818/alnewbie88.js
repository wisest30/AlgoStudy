/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minAbsoluteSumDiff = function(nums1, nums2) {
    let diffArr = [];
    for (let i = 0; i < nums1.length; i++) {
        diffArr[i] = Math.abs(nums1[i] - nums2[i]);
    }
	
    let sortedNums1 = nums1.sort(function(a, b) { return a - b; });
    
    // targetVal 와 가장 근사한 숫자를 nums1 에서 찾는다 (이진 탐색)
    var getValueNearestTo = function(targetVal) {
        let l = 0;
        let r = sortedNums1.length - 1;
        let m;
        while (l < r) {
            m = Math.ceil((l + r + 1) / 2);
            if (sortedNums1[m] <= targetVal) {
                l = m;
            }
            else
                r = m - 1;
        }
        
        if (sortedNums1[l + 1] !== undefined) {
            let diff1 = Math.abs(targetVal - sortedNums1[l]);
            let diff2 = Math.abs(targetVal - sortedNums1[l + 1]);
            return diff1 <= diff2 ? sortedNums1[l] : sortedNums1[l + 1];
        }
        
        return sortedNums1[l];
    }
    
    let maxDeltaValue = 0;
    let maxDeltaValueIdx = -1;
    let newValOnMaxDeltaValue = undefined;
    for (let i = 0; i < diffArr.length; i++) {
        if (diffArr[i] === 0)
            continue;
        
        let newVal = getValueNearestTo(nums2[i]);
        let deltaValue = diffArr[i] - Math.abs(newVal - nums2[i]);
        if (deltaValue > maxDeltaValue) {
            maxDeltaValue = deltaValue;
            maxDeltaValueIdx = i;
            newValOnMaxDeltaValue = newVal;
        }
    }
    
    if (maxDeltaValueIdx >= 0) {
        diffArr[maxDeltaValueIdx] = Math.abs(newValOnMaxDeltaValue - nums2[maxDeltaValueIdx]);
    }
    
    let sumDiff = diffArr.reduce((accum, curValue) => accum + curValue, 0);
    return sumDiff % (1000000000 + 7);
};