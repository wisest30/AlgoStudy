class Solution:
    def findAllPeople(self, n: int, M: List[List[int]], f: int) -> List[int]:
        M.sort(key = lambda x : x[2])
        know = [False] * n
        know[0] = know[f] = True
        
        def dfs(cur, g, visited) :
            if cur in visited :
                return
            visited.add(cur)
            know[cur] = True
            for nxt in g[cur] :
                dfs(nxt, g, visited)
        
        left = right = 0
        while left < len(M) :
            while right < len(M) and M[left][2] == M[right][2] :
                right += 1
            
            g = defaultdict(list)
            for k in range(left, right) :
                g[M[k][0]].append(M[k][1])
                g[M[k][1]].append(M[k][0])
            
            visited = set()
            for i in g :
                if know[i] :
                    dfs(i, g, visited)
            
            left = right
        
        return [i for i in range(n) if know[i]]
