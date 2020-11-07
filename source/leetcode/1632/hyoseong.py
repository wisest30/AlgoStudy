class Solution:
    def matrixRankTransform(self, matrix: List[List[int]]) -> List[List[int]]:
        n = len(matrix)
        m = len(matrix[0])
        
        G = [0] * (n + m)
        G_max = [0] * (n + m)
        def get_group(x) :
            if G[x] == x :
                return x
            G[x] = get_group(G[x])
            return G[x]
        def merge_group(x, y) :
            gx, gy = get_group(x), get_group(y)
            G_max[gy] = max(G_max[gx], G_max[gy])
            G[gx] = gy
        
        D = defaultdict(list)
        for i in range(n) :
            for j in range(m) :
                D[matrix[i][j]].append([i, j])
        
        ret = [[0] * m for _ in range(n)]
        rank = [0] * (n + m)
        for key in sorted(D.keys()) :
            G = list(range(n + m))
            G_max = rank[:]
            for i, j in D[key] :
                merge_group(i, n + j)
        
            for i, j in D[key] :
                rank[i] = rank[n + j] = ret[i][j] = G_max[get_group(i)] + 1

        return ret
