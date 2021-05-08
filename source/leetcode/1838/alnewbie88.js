/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxFrequency = function(nums, k) {
    nums.sort(function(a, b) { return a - b; });
    
    let maxFrequency = 1;
    for (let i = 0; i < nums.length; i++) {
        // skip same numbers (for avoid TL)
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[i] !== nums[j]) {
                break;
            }
            i = j;
        }
        
        let remainedK = k;
        let frequency = 1;
        for (let j = i - 1; j >= 0 && remainedK > 0; j--) {
            let needK = nums[i] - nums[j];
            if (remainedK < needK) {
                break;
            }
            
            remainedK -= needK;
            frequency++;
        }
        
        if (frequency > maxFrequency) {
            maxFrequency = frequency;
        }
    }
    
    return maxFrequency;
};