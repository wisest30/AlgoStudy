class Solution:
    def numSub(self, s: str) -> int:
        return sum(len(a) * (len(a) + 1) / 2 for a in s.split('0')) % (10**9 + 7)
