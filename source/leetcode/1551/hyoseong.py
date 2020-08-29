class Solution:
    def minOperations(self, n: int) -> int:
        m = n // 2
        if n % 2 :
            return m * (m+1)
        else :
            return m * m
