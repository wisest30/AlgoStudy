import sys
sys.setrecursionlimit(10 ** 5)
class Solution:
    def minimumEffortPath(self, A: List[List[int]]) -> int:
        R = len(A)
        C = len(A[0])
        dy = [-1, 0, 0, 1]
        dx = [0, -1, 1, 0]
        def dfs(y, x, val) :
            if y == R - 1 and x == C - 1 :
                return True
            visited[y][x] = True
            ret = False
            for i in range(4) :
                ny = y + dy[i]
                nx = x + dx[i]
                if ny < 0 or nx < 0 or ny >= R or nx >= C :
                    continue
                if visited[ny][nx] :
                    continue
                if abs(A[ny][nx] - A[y][x]) > val :
                    continue
                ret |= dfs(ny, nx, val)

            return ret
        
        l, r = -1, 10 ** 6
        while l + 1 < r :
            visited = [[False] * C for _ in range(R)]
            m = (l + r) // 2
            if dfs(0, 0, m) :
                r = m
            else :
                l = m
        return r
            
            
            
