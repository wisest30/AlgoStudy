class Solution:
    def minimumTime(self, s: str) -> int:        
        A = [0]
        for i in range(len(s)) : A.append(min(A[-1] + int(s[i]) * 2, i + 1))
        for i in range(len(s)) : A[i] += len(s) - i
        return min(A)
