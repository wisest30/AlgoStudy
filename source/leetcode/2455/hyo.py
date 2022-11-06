class Solution:
    def averageValue(self, nums: List[int]) -> int:
        A = [num for num in nums if num % 6 == 0]
        return sum(A) // len(A) if A else 0
