class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        dy, dx = [-1, 0, 0, 1], [0, -1, 1, 0]
        n, m = len(grid), len(grid[0])
        D = [[float('inf')] * m for _ in range(n)]
        
        q = []
        heappush(q, [0, 0, 0])
        while q :
            d, y, x = heappop(q)
            if d >= D[y][x] :
                continue
            D[y][x] = d
            for i in range(4) :
                ny, nx = y + dy[i], x + dx[i]
                if ny < 0 or ny >= n or nx < 0 or nx >= m :
                    continue
                heappush(q, [d + grid[ny][nx], ny, nx])
        
        return D[-1][-1]
