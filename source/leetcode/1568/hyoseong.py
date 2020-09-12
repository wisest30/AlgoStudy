class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        visited = [[False] * m for i in range(n)]
        dy = [-1, 0, 0, 1]
        dx = [0, -1, 1, 0]
        def dfs(y, x) :
            if visited[y][x] :
                return
            visited[y][x] = True

            for i in range(4) :
                ny = dy[i] + y
                nx = dx[i] + x
                if 0 <= ny < n and 0 <= nx < m and grid[ny][nx] :
                    dfs(ny, nx)
        
        def get_cnt() :
            cnt = 0
            for y in range(n) :
                for x in range(m) :
                    if not visited[y][x] and grid[y][x]:
                        cnt += 1
                        dfs(y, x)
            return cnt
        
        if get_cnt() != 1 :
            return 0
               
        for y in range(n) :
            for x in range(m) :
                if grid[y][x] == 0 : continue
                grid[y][x] = 0
                visited = [[False] * m for i in range(n)]
                if get_cnt() != 1 :
                    return 1
                grid[y][x] = 1
        return 2
                    
