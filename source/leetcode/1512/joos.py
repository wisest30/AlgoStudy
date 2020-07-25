class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        return sum(k * (k - 1) // 2 for k in collections.Counter(A).values())
