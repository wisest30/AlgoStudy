class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        F = [0] * n
        H = [[0] * n for _ in range(n)]
        for u, v in roads :
            F[u] += 1
            F[v] += 1
            H[u][v] += 1
            H[v][u] += 1
        
        ret = 0
        for u in range(n) :
            for v in range(u+1, n) :
                ret = max(ret, F[u] + F[v] - H[u][v])
        return ret
        
