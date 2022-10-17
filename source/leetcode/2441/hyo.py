class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        s = set(nums)
        return max([-1] + [num for num in nums if -num in s])
