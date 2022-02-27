class Solution:
    def minSteps(self, s: str, t: str) -> int:
        return sum(abs(s.count(c) - t.count(c)) for c in "abcdefghijklmnopqrstuvwxyz")
