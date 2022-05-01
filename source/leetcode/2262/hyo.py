class Solution:
    def appealSum(self, s: str) -> int:
        ret = 0
        for c in set(s) :
            last = -1
            for i in range(len(s)) :
                if s[i] == c :
                    last = i
                ret += last + 1
        
        return ret