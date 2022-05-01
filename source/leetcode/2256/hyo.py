class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n, ls, rs = len(nums), 0, sum(nums)
        min_val, ret = 10 ** 10, -1
        for i in range(n) :
            ls += nums[i]
            rs -= nums[i]
            val = ls // (i + 1) if i == n - 1 else abs(ls // (i + 1) - rs // (n - i - 1))
            if val < min_val :
                ret, min_val = i, val
        
        return ret