class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        return [i for i in range(len(nums)) if key in nums[max(0, i - k) : i + k + 1]]
