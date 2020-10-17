class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        prev = -1
        for idx, val in enumerate(nums):
            if val >= n - idx and n - idx > prev:
                return n - idx
            prev = val
        return -1
