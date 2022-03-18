class Solution:
    def minimumWeight(self, n: int, edges: List[List[int]], src1: int, src2: int, dest: int) -> int:
        inf = 10 ** 15
        def dijkstra(s, g) :
            nonlocal inf
            q, ret = [], [inf] * n
            heapq.heappush(q, [0, s])
            
            while q :
                d, cur = heapq.heappop(q)
                if ret[cur] == inf :
                    ret[cur] = d
                    for e in g[cur] :
                        heapq.heappush(q, [d + e[1], e[0]])
            
            return ret
        
        g, bg = [[] for _ in range(n)], [[] for _ in range(n)]
        for e in edges :
            g[e[0]].append([e[1], e[2]])
            bg[e[1]].append([e[0], e[2]])

        d1, d2, d3 = dijkstra(src1, g), dijkstra(src2, g), dijkstra(dest, bg)
        ret = min(d1[i] + d2[i] + d3[i] for i in range(n))
        
        return -1 if ret >= inf else ret
