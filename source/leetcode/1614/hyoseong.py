class Solution:
    def maxDepth(self, s: str) -> int:
        ret = 0
        p = 0
        for c in s :
            if c == '(' :
                p += 1
            elif c == ')' :
                p -= 1
            ret = max(ret, p)
        return ret
