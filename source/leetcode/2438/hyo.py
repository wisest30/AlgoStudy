class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        import numpy as np
        MOD = 1000000007
        A = [2 ** i for i in range(32) if n & (2 ** i)]
        ret = []
        for q in queries :
            l, r = q
            a = 1
            for i in range(l, r + 1) :
                a = a * A[i] % MOD
            ret.append(a)
        
        return ret
