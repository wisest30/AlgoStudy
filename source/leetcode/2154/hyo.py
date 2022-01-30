class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        return functools.reduce(lambda acc, x : acc * 2 if x == acc else acc, sorted(nums), original)
