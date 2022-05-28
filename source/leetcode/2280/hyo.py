class Solution:
    def minimumLines(self, s: List[List[int]]) -> int:
        s.sort()
        is_strait = lambda i : \
            (s[i][0] - s[i-1][0]) * (s[i+1][1] - s[i][1]) == \
            (s[i+1][0] - s[i][0]) * (s[i][1] - s[i-1][1])
        
        return len(s) - 1 - sum(is_strait(i) for i in range(1, len(s) - 1))
