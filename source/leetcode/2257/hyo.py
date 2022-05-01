class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        A = [[0] * n for _ in range(m)]
        for g in guards : A[g[0]][g[1]] = 1
        for w in walls : A[w[0]][w[1]] = 1
        
        dy, dx = [-1, 0, 0, 1], [0, -1, 1, 0]
        for g in guards :
            for i in range(4) :
                y, x = g[0] + dy[i], g[1] + dx[i]
                while 0 <= y < m and 0 <= x < n and A[y][x] <= 0:
                    A[y][x] = -1
                    y += dy[i]
                    x += dx[i]
        
        return sum(1 for x in range(n) for y in range(m) if A[y][x] == 0)