class Solution:
    def numSteps(self, s: str) -> int:
        step = 0
        s = int(s, base=2)
        while s != 1:
            if s & 1:
                s += 1
            else:
                s //= 2    
            step += 1
        
        return step
