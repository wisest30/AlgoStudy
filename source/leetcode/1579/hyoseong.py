class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
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

        def process(t) :
            ret = 0
            for e in edges :
                if e[0] == t :
                    u, v = e[1] - 1, e[2] - 1
                    if get_group(u) != get_group(v) :
                        merge_group(u, v)
                    else :
                        ret += 1
            return ret
    
        def get_group_cnt() :
            S = set()
            for i in range(n) :
                S.add(get_group(i))
            return len(S)

        ret = 0
        ret += process(3)
        
        old_G = G.copy()
        ret += process(1)
        if get_group_cnt() != 1 :
            return -1
        
        G = old_G.copy()
        ret += process(2)
        if get_group_cnt() != 1 :
            return -1
        
        return ret
                
