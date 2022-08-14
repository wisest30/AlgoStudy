class Solution:
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        import sys
        sys.setrecursionlimit(10 ** 5 + 10)
        
        g = [[] for _ in range(n)]
        restricted = set(restricted)
        for e in edges :
            if e[0] not in restricted and e[1] not in restricted :
                g[e[0]].append(e[1])
                g[e[1]].append(e[0])
        
        def dfs(cur, prev) :
            cnt = 1
            for nxt in g[cur] :
                if nxt != prev :
                    cnt += dfs(nxt, cur)
            
            return cnt
        
        return dfs(0, -1)
        
        
