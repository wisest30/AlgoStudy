class Solution:
    def maximumTop(self, nums: List[int], k: int) -> int:
        return max([num for i, num in enumerate(nums) if (k == i or i + 1 < k if len(nums) > 1 else k % 2 == 0)] + [-1])
