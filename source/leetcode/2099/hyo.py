class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        return [v for i, v in sorted(sorted(enumerate(nums), key = lambda x : -x[1])[:k])]
