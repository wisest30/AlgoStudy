class Solution:
    def maxScoreIndices(self, nums: List[int]) -> List[int]:
        cnt0, cnt1 = 0, sum(nums)
        max_val, ret = cnt1, [0]
        
        for i in range(len(nums)) :
            cnt0 += nums[i] ^ 1
            cnt1 -= nums[i]
            if cnt0 + cnt1 > max_val :
                max_val = cnt0 + cnt1
                ret = [i+1]
            elif cnt0 + cnt1 == max_val :
                ret.append(i+1)
                
        return ret
