class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        L = [0]
        for i in range(20) :
            L.append(L[-1] * 2 + 1)
        
        def solve(n, k) :
            if n == 1 and k == 1 : return 0
            if k <= L[n] // 2 : return solve(n-1, k)
            elif k == L[n] // 2 + 1 : return 1
            else : return solve(n-1, L[n] - k + 1) ^ 1
        return str(solve(n, k))
