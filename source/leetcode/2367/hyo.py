class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        return sum(1 if num + diff in nums and num + 2 * diff in nums else 0 for num in nums)
