class Solution:
    def maxTrailingZeros(self, grid: List[List[int]]) -> int:
        cnts = [[0, 0] for i in range(1001)]
        for i in range(2, 1001) :
            if i % 2 == 0 :
                cnts[i][0] = cnts[i // 2][0] + 1
            if i % 5 == 0 :
                cnts[i][1] = cnts[i // 5][1] + 1

        n, m = len(grid), len(grid[0])
        A = [[[0, 0] for _ in range(m + 1)] for _ in range(n + 1)]
        B = [[[0, 0] for _ in range(m + 1)] for _ in range(n + 1)]
        
        for y in range(n) :
            for x in range(m) :
                for i in range(2) :
                    A[y+1][x][i] = A[y][x][i] + cnts[grid[y][x]][i]
                    B[y][x+1][i] = B[y][x][i] + cnts[grid[y][x]][i]
        
        ret = 0
        for y in range(n) :
            for x in range(m) :
                for u in range(2) :
                    for l in range(2) :
                        cnt_u = A[y+1][x] if u else [A[n][x][i] - A[y][x][i] for i in range(2)]
                        cnt_l = B[y][x] if l else [B[y][m][i] - B[y][x+1][i] for i in range(2)]
                        ret = max(ret, min(cnt_u[0] + cnt_l[0], cnt_u[1] + cnt_l[1]))

        return ret
                
