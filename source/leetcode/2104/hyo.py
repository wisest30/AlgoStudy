class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        ret = 0
        for i in range(len(nums)) :
            mine = maxe = nums[i]
            for j in range(i + 1, len(nums)) :
                mine = min(mine, nums[j])
                maxe = max(maxe, nums[j])
                ret += maxe - mine
        return ret
