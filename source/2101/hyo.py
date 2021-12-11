class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        n = len(bombs)
        g = [[] for i in range(n)]
        for i in range(n) :
            for j in range(n) :
                if i != j and (bombs[i][0] - bombs[j][0]) ** 2 + (bombs[i][1] - bombs[j][1]) ** 2 <= bombs[i][2] ** 2:
                    g[i].append(j)
        ret = 0
        for s in range(n) :
            cnt = 0
            visited = [False] * n
            st = [s]
            while st :
                cur = st.pop()
                if not visited[cur] :
                    visited[cur] = True
                    cnt += 1
                    for nxt in g[cur] :
                        st.append(nxt)
            
            ret = max(ret, cnt)
        
        return ret
