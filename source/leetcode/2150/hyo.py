class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
        C = Counter(nums)
        return [i for i in nums if C[i] == 1 and C[i-1] == 0 and C[i+1] == 0]
