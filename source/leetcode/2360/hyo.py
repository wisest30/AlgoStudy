class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        n = len(edges)
        D = [-1] * n
        inPath = [False] * n
        ret = -1
        def dfs(cur, depth) :
            nonlocal ret
            D[cur] = depth
            inPath[cur] = True
            
            nxt = edges[cur]
            if nxt != -1 :
                if inPath[nxt] :
                    ret = max(ret, D[cur] - D[nxt] + 1)
                elif D[nxt] == -1 :
                    dfs(nxt, depth + 1)
            
            inPath[cur] = False

        for i in range(n) :
            if D[i] == -1 :
                dfs(i, 0)

        return ret
