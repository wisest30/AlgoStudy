class Solution:
    def maximumSubsequenceCount(self, text: str, pattern: str) -> int:
        C, ret = Counter(), 0
        for c in text :
            if c == pattern[1] :
                ret += C[pattern[0]]
            C[c] += 1
        
        ret += max(C[pattern[0]], C[pattern[1]])
        return ret
        
