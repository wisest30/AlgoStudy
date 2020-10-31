import numpy as np
class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        n = len(s)
        A = []
        ga = math.gcd(a, 10)
        gb = math.gcd(b, n)
        for i in range(0, 10, ga) :
            for j in range(0, 10, ga) :
                L = list(map(int, s))
                for k in range(n) :
                    if k % 2 == 0 :
                        L[k] = (L[k] + j) % 10
                    else :
                        L[k] = (L[k] + i) % 10
                
                t = "".join(list(map(str, L)))
                A.append(t)
                for k in range(gb, n, gb) :
                    A.append(t[-k:] + t[:-k])

                if b % 2 == 0 :
                    break
        return min(A)
            
        
            
