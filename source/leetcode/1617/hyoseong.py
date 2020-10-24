class Solution:
    def countSubgraphsForEachDiameter(self, n: int, E: List[List[int]]) -> List[int]:
        edges = [[] for _ in range(n)]
        for e in E :
            u, v = e[0]-1, e[1]-1
            edges[u].append(v)
            edges[v].append(u)

        def dfs(subset, start) :
            visited = 0
            st = [(start, 0)]
            max_dis = 0
            while st :
                cur, d = st.pop()
                if visited & (1 << cur) :
                    continue
                visited |= 1 << cur
                max_dis = max(max_dis, d)
                for nxt in edges[cur] :
                    if subset & (1 << nxt) :
                        st.append((nxt, d+1))
            
            return (visited, max_dis)
                
        def check(subset) :
            ret = 0
            for i in range(n) :
                if subset & (1 << i) :
                    visited, max_dis = dfs(subset, i)
                    if visited != subset :
                        return 0
                    ret = max(ret, max_dis)
            return ret
        
        ret = [0] * (n-1)
        for subset in range(1 << n) :
            max_dis = check(subset)
            if max_dis > 0 :
                ret[max_dis - 1] += 1

        return ret
