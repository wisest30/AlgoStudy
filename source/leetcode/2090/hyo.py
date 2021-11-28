class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        ret = [-1] * n
        s = sum(nums[:min(n, k * 2)])
        for i in range(k, n - k) :
            s += nums[i + k]
            ret[i] = s // (2 * k + 1)
            s -= nums[i - k]

        return ret
            
