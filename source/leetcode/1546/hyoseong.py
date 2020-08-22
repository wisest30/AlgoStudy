class Solution:
    def maxNonOverlapping(self, nums: List[int], target: int) -> int:
        S, su, ret, left = set([0]), 0, 0, 0
        for n in nums :
            su += n
            if su - target in S : 
                S = set([0])
                su = 0
                ret = ret + 1
            else : S.add(su)
        return ret
        
