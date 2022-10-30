class Solution:
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        def f(s) :
            h, m = int(s[:2]), int(s[3:])
            return h * 60 + m
        
        s0, e0 = f(event1[0]), f(event1[1])
        s1, e1 = f(event2[0]), f(event2[1])
        
        return s0 <= e1 and s1 <= e0
