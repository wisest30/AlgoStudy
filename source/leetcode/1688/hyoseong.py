class Solution:
    def numberOfMatches(self, n: int) -> int:
        ret = 0
        while n > 1 :
            ret += n // 2
            n = (n + 1) // 2
        
        return ret
