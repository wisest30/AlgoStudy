class Solution:
    def longestPrefix(self, s: str) -> str:
        ans = ""
        for i in range(1, len(s)):
            if s.startswith(s[i:]):
                ans = s[i:]
                break
        return ans
