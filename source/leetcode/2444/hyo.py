class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        l, r, p, q, ret = 0, 0, -1, -1, 0
        for i in range(len(nums)) :
            if nums[i] == minK : p = i
            if nums[i] == maxK : q = i
            if nums[i] < minK or nums[i] > maxK :
                l = i + 1
            if p >= l and q >= l :
                ret += min(p, q) - l + 1
        return ret
