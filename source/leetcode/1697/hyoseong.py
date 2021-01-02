class Solution:
    def distanceLimitedPathsExist(self, n: int, edgeList: List[List[int]], queries: List[List[int]]) -> List[bool]:
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
        
        edgeList.sort(key = lambda x : x[2])
        
        for i in range(len(queries)) :
            queries[i].append(i)
        
        queries.sort(key = lambda x : x[2])
        
        i = j = 0
        while i < len(edgeList) and j < len(queries):
            if edgeList[i][2] < queries[j][2] :
                merge_group(edgeList[i][0], edgeList[i][1])
                i += 1
            else :
                gx, gy = get_group(queries[j][0]), get_group(queries[j][1])
                queries[j].append(gx == gy)
                j += 1
        
        while j < len(queries) :
            gx, gy = get_group(queries[j][0]), get_group(queries[j][1])
            queries[j].append(gx == gy)
            j += 1
        
        queries.sort(key = lambda x : x[3])
        ret = [q[4] for q in queries]
        return ret
