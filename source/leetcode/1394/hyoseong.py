from collections import Counter as ct
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        C = ct(arr)

        ret = -1
        for c in C :
            if c == C[c] :
                ret = max(ret, c)
        
        return ret
