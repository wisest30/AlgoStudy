class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        ret, cur, p = 0, 0, 1
        for d in reversed(s) :
            if d == '0' :
                ret += 1
                p *= 2
            elif d == '1' and cur + p <= k :
                cur += p
                ret += 1
                p *= 2
        
        return ret
