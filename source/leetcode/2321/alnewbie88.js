/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maximumsSplicedArray = function(nums1, nums2) {
    let getMaxBenefit = function(arr1, arr2) {
        let maxBenefit = 0;
        let sumBenefit = 0;
        for (let i = 0; i < arr1.length; i++) {
            const benefit = arr2[i] - arr1[i];
            sumBenefit = Math.max(benefit, sumBenefit + benefit);
            maxBenefit = Math.max(maxBenefit, sumBenefit);
        }
        
        return maxBenefit;
    }
    
    const sum1 = nums1.reduce((accum, cur) => accum + cur, 0);
    const sum2 = nums2.reduce((accum, cur) => accum + cur, 0);
    return Math.max(sum1 + getMaxBenefit(nums1, nums2), sum2 + getMaxBenefit(nums2, nums1));
};