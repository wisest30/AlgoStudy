class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        func = lambda i : max if i % 2 else min
        while len(nums) > 1 :
            nums = [func(i)(nums[2 * i], nums[2 * i + 1]) for i in range(len(nums) // 2)]
        
        return nums[0]
