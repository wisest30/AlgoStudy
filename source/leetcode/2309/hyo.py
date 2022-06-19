class Solution:
    def greatestLetter(self, s: str) -> str:
        s = set(s)
        for c in reversed("ABCDEFGHIJKLMNOPQRSTUVWXYZ") :
            if c in s and c.lower() in s :
                return c
        return ""
