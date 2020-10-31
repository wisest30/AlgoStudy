class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        n = len(s)
        
        ret = '9' * n
        visited = set()
        A = [s]
        while A :
            cur = A.pop()
            if cur in visited :
                continue
            visited.add(cur)
            ret = min(ret, cur)
            L = list(cur)
            for i in range(1, n, 2) :
                L[i] = str((int(L[i]) + a) % 10)
            nxt = "".join(L)
            A.append(nxt)
            
            L = list(cur)
            nxt = cur[-b:] + cur[:-b]
            A.append(nxt)
            
        return ret
