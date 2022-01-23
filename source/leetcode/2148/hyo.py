class Solution:
    def countElements(self, nums: List[int]) -> int:
        return len([i for i in nums if i < max(nums) and i > min(nums)])
