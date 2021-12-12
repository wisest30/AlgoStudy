class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        A = [0] * 200001
        for f in fruits :
            A[f[0]] = f[1]
            
        for i in range(1, len(A)) :
            A[i] += A[i-1]
        
        def f(l, r) :
            l = min(max(l, 0), len(A) - 1)
            r = min(max(r, 0), len(A) - 1)
            return A[r] if l == 0 else A[r] - A[l-1]
        
        ret = 0
        for l in range(0, startPos + 1) :
            d = startPos - l
            remain = k - 2 * d            
            if remain >= 0 : ret = max(ret, f(l, startPos + remain))
            remain = k - d
            if remain >= 0 : ret = max(ret, f(l, startPos + remain // 2))
        
        return ret
