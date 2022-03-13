/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minimalKSum = function(nums, k) {
    let set = new Set();
    nums.forEach(num => set.add(num));
    
    let minSum = k * (k + 1) * 0.5;
    let appearCnt = 0;
    for (let num of set) {
        if (num <= k) {
            do {
                appearCnt++;
            } while (set.has(k + appearCnt));

            set.add(k + appearCnt);
            minSum += k + appearCnt - num;
        }
    }
    
    return minSum;
};