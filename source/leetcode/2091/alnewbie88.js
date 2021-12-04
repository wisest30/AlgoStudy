/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDeletions = function(nums) {
    if (nums.length === 1) { return 1; }
    if (nums.length === 2) { return 2; }
    
    let min = {idx: -1, val: 100001};
    let max = {idx: -1, val: -100001};
    for (let i = 0; i < nums.length; i++) {
        const val = nums[i];
        if (val < min.val) {
            min.idx = i;
            min.val = val;
        }
        if (val > max.val) {
            max.idx = i;
            max.val = val;
        }
    }
    
    // shift or pop 중에 비용이 작은 부분을 택하여 제거하는 것을 두번 반복한 비용
    let answer = 0;
	
    let shiftCntForRemoveMinVal = min.idx + 1;
    let shiftCntForRemoveMaxVal = max.idx + 1;
    let popCntForRemoveMinVal = nums.length - min.idx;
    let popCntForRemoveMaxVal = nums.length - max.idx;
    const minShift = Math.min(shiftCntForRemoveMinVal, shiftCntForRemoveMaxVal);
    const minPop = Math.min(popCntForRemoveMinVal, popCntForRemoveMaxVal);
    if (minShift < minPop) {
        answer += minShift;
        const minIsRemoved = minShift === min.idx + 1;
        if (minIsRemoved) {
            shiftCntForRemoveMaxVal -= minShift;
            answer += Math.min(shiftCntForRemoveMaxVal, minPop);
        } else {
            shiftCntForRemoveMinVal -= minShift;
            answer += Math.min(shiftCntForRemoveMinVal, minPop);
        }
    } else {
        answer += minPop;
        const minIsRemoved = minPop === (nums.length - min.idx);
        if (minIsRemoved) {
            popCntForRemoveMaxVal -= minPop;
            answer += Math.min(popCntForRemoveMaxVal, minShift);
        } else {
            popCntForRemoveMinVal -= minPop;
            answer += Math.min(popCntForRemoveMinVal, minShift);
        }
    }
    
    return answer;
};
