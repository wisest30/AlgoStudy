class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], f: int) -> List[int]:
        meetings.sort(key = lambda x : x[2])
        know = [False] * n
        know[0] = know[f] = True
        
        def dfs(cur, g, visited) :
            if cur in visited :
                return
            visited.add(cur)
            know[cur] = True
            for nxt in g[cur] :
                dfs(nxt, g, visited)
        
        for _, M in groupby(meetings, key = lambda x : x[2]) :
            g = defaultdict(list)
            for e in M :
                g[e[0]].append(e[1])
                g[e[1]].append(e[0])
            
            visited = set()
            for i in g :
                if know[i] :
                    dfs(i, g, visited)
        
        return [i for i in range(n) if know[i]]
