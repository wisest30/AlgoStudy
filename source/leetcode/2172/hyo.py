class Solution:
    def maximumANDSum(self, nums: List[int], numSlots: int) -> int:
        @lru_cache(None)
        def recur(i, subset) :
            if i == len(nums) : return 0
            return max([recur(i+1, subset + 3 ** j) + (nums[i] & (j + 1)) for j in range(numSlots) if subset // 3 ** j % 3 < 2])
        
        return recur(0, 0)
