/**
 * @param {number[]} nums
 * @return {number}
 */
var minSwaps = function(nums) {
    const n = nums.length;
    let k = 0;  // totalOneCount on nums
    nums.forEach(num => num && k++);
    nums = nums.concat(nums.slice());   // make circular
    
    let sum = 0;
    let answer = 100000;
    for (let i = 0; i < n; i++) {
        if (i === 0) {
            for (let j = 0; j < k; j++) {
                sum += nums[j];
            }
        } else {
            sum = sum - nums[i - 1] + nums[i + k - 1];
        }
        answer = Math.min(answer, k - sum);
    }
    
    return answer;
};