/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minOperations = function(nums1, nums2) {
    let len1 = nums1.length;
    let len2 = nums2.length;
    let minSumLongLen = len1 >= len2 ? len1 : len2;
    let maxSumShortLen = len1 < len2 ? len1 * 6 : len2 * 6;
    if (minSumLongLen > maxSumShortLen)
        return -1;
    
    let sum1 = nums1.reduce((accum, val) => accum + val);
    let sum2 = nums2.reduce((accum, val) => accum + val);
    nums1.sort(function(a, b) { return a - b; });
    nums2.sort(function(a, b) { return a - b; });
    
    let num1IdxOffsetL = 0;
    let num1IdxOffsetR = 0;
    let num2IdxOffsetL = 0;
    let num2IdxOffsetR = 0;
    let operations = 0;
    while (true) {
        let diff = sum1 - sum2;
        if (diff === 0) { break; }
        if (diff > 0) {
            // nums1 에서 빼거나, nums2 에서 더함 (더많이 빼거나 더할수 있는 숫자 택함. 같다면 빼는쪽을 택함)
            if ((nums1[len1 - 1 - num1IdxOffsetR] - 1) >= (6 - nums2[num2IdxOffsetL])) {
                let beforeVal = nums1[len1 - 1 - num1IdxOffsetR];
                nums1[len1 - 1 - num1IdxOffsetR] = Math.max(1, nums1[len1 - 1 - num1IdxOffsetR] - diff);
                sum1 -= beforeVal - nums1[len1 - 1 - num1IdxOffsetR];
                num1IdxOffsetR++;
            } else {
                let beforeVal = nums2[num2IdxOffsetL];
                nums2[num2IdxOffsetL] = Math.min(diff + nums2[num2IdxOffsetL], 6);
                sum2 += nums2[num2IdxOffsetL] - beforeVal;
                num2IdxOffsetL++;
            }
        } else {
            // nums1 에서 더하거나, nums2 에서 뺌 (더많이 빼거나 더할수 있는 숫자 택함. 같다면 빼는쪽을 택함)
            if ((nums2[len2 - 1 - num2IdxOffsetR] - 1) >= (6 - nums1[num1IdxOffsetL])) {
                let beforeVal = nums2[len2 - 1 - num2IdxOffsetR];
                nums2[len2 - 1 - num2IdxOffsetR] = Math.max(1, nums2[len2 - 1 - num2IdxOffsetR] - Math.abs(diff));
                sum2 -= beforeVal - nums2[len2 - 1 - num2IdxOffsetR];
                num2IdxOffsetR++;
            } else {
                let beforeVal = nums1[num1IdxOffsetL]; 
                nums1[num1IdxOffsetL] = Math.min(Math.abs(diff) + nums1[num1IdxOffsetL], 6);
                sum1 += nums1[num1IdxOffsetL] - beforeVal;
                num1IdxOffsetL++;
            }
        }
        
        operations++;
        //sum1 = nums1.reduce((accum, val) => accum + val);
        //sum2 = nums2.reduce((accum, val) => accum + val);
        //nums1.sort(function(a, b) { return a - b; });
        //nums2.sort(function(a, b) { return a - b; });
    }
    
    return operations;
};