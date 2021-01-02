class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:        
        n = len(nums)
        ps = [0] * (n + 1)
        for i in range(n) :
            ps[i+1] = ps[i] + nums[i]
        
        inWindow = [False] * 10001
        ret = i = j = 0
        while j < n :
            if inWindow[nums[j]] == False :
                inWindow[nums[j]] = True
                j += 1
                ret = max(ret, ps[j] - ps[i])
            else :
                inWindow[nums[i]] = False
                i += 1
        
        return ret
