class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        D = defaultdict(int)
        g = defaultdict(list)
        for u, v in pairs :
            D[u] += 1
            D[v] -= 1
            g[u].append(v)
        
        s = pairs[0][0]
        for k in D :
            if D[k] > 0 :
                s = k
                break
        
        def dfs(cur, path) :
            while g[cur] :
                nxt = g[cur].pop()
                dfs(nxt, path)
            path.append(cur)
        
        path = []
        dfs(s, path)
        path.reverse()
        return [[path[i], path[i+1]] for i in range(len(path) - 1)]
        
