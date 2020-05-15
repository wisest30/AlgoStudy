class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        index = [i for i, n in enumerate(nums) if n]
        return all(b - a > k for a, b in zip(index, index[1:]))
