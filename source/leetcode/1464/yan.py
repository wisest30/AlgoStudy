class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        x, y = sorted(nums)[-2:]
        return (x - 1) * (y - 1)
