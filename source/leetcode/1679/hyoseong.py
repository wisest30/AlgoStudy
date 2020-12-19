class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        C = Counter(nums)
        ret = 0
        for key in C :
            ret += min(C[key], C[k - key])
        ret //= 2
        return ret
