class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        G = [i for i in range(n)]
        G_cnt = [1] * n
        def get_group(x) :
            if G[x] == x :
                return x
            G[x] = get_group(G[x])
            return G[x]

        def merge_group(x, y) :
            gx = get_group(x)
            gy = get_group(y)
            if gx == gy :
                return
            if gx > gy :
                gx, gy = gy, gx
            G[gx] = G[gy]
            G_cnt[gy] += G_cnt[gx]
        
        A = []
        for i in range(n) :
            for j in range(i+1, n) :
                d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                A.append([i, j, d])
        
        A.sort(key = lambda x : x[2])
        ret = 0
        for i in range(len(A)) :
            g1 = get_group(A[i][0])
            g2 = get_group(A[i][1])
            if g1 == g2 : continue
            ret += A[i][2]
            merge_group(g1, g2)
        return ret
