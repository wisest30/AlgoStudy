class Solution:
    def arrayChange(self, nums: List[int], operations: List[List[int]]) -> List[int]:
        d0, d1 = dict(), dict()
        for o in operations :
            if o[0] in d1 :
                p = d1[o[0]]
                d0[p] = o[1]
                del d1[o[0]]
                d1[o[1]] = p
            else :
                d0[o[0]] = o[1]
                d1[o[1]] = o[0]
        
        for i in range(len(nums)) :
            if nums[i] in d0 :
                nums[i] = d0[nums[i]]
        
        return nums
