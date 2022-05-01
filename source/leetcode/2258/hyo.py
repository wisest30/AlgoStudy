class Solution:
    def maximumMinutes(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        A = [[float('inf')] * n for _ in range(m)] 
        q = deque([y, x, 0] for x in range(n) for y in range(m) if grid[y][x] == 1)
        dy, dx = [-1, 0, 0, 1], [0, -1, 1, 0]
        visited = [[False] * n for _ in range(m)]
        while q :
            y, x, t = q.popleft()
            if visited[y][x] :
                continue
            
            visited[y][x] = True
            A[y][x] = t
            for i in range(4) :
                ny = y + dy[i]
                nx = x + dx[i]
                if ny < 0 or ny >= m or nx < 0 or nx >= n :
                    continue
                if grid[ny][nx] != 0 :
                    continue
                q.append([ny, nx, t+1])
        
        def check(mm) :
            visited = [[False] * n for _ in range(m)]
            q = deque()
            q.append([0, 0, mm])
            while q :
                y, x, t = q.pop()
                if visited[y][x] :
                    continue
                
                visited[y][x] = True
                for i in range(4) :
                    ny = y + dy[i]
                    nx = x + dx[i]
                    if ny < 0 or ny >= m or nx < 0 or nx >= n :
                        continue
                    if grid[ny][nx] != 0 :
                        continue
                    if ny == m-1 and nx == n-1 and A[ny][nx] >= t+1 :
                        return True
                    if A[ny][nx] <= t+1 :
                        continue
                    q.append([ny, nx, t+1])
        
            return False
        
        l, r = -1, 10 ** 9 + 1
        while l + 1 < r :
            mm = (l + r) // 2
            if check(mm) :
                l = mm
            else :
                r = mm
        
        return l