class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        max_val = max(a, b, c)
        others = a + b + c - max_val
        if max_val > others:
            return others
        else:
            return int((a + b + c) / 2)
