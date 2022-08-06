class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        n = len(edges)
        def dfs(cur, depth, visited, D) :
            if visited[cur] :
                return
            visited[cur] = True
            D[cur] = depth
            
            if edges[cur] != -1 :
                dfs(edges[cur], depth + 1, visited, D)
        
        inf = 10 ** 9
        D1, D2 = [inf] * n, [inf] * n
        dfs(node1, 0, [False] * n, D1)
        dfs(node2, 0, [False] * n, D2)
        
        t = min((max(D1[i], D2[i]), i) for i in range(n))
        return -1 if t[0] == inf else t[1]
