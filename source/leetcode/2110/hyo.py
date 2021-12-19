class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        prev = -121212
        ret = 0
        for p in prices :
            if p == prev - 1 : cnt += 1
            else : cnt = 1

            ret += cnt
            prev = p
        
        return ret
