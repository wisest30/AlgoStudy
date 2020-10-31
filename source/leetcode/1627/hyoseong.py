class Solution:
    def areConnected(self, n: int, threshold: int, queries: List[List[int]]) -> List[bool]:
        n += 1
        G = [i for i in range(n)]
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
        
        for i in range(threshold + 1, n) :
            for j in range(i * 2, n, i) :
                merge_group(i, j)
        
        ret = [get_group(q[0]) == get_group(q[1]) for q in queries]
        return ret
