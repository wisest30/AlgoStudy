class Solution:
    def countPyramids(self, grid: List[List[int]]) -> int:
        ret, r, c = 0, len(grid), len(grid[0])
        for i in range(2) :
            if i == 1 : grid.reverse()
            dp = copy.deepcopy(grid)
            
            for y in range(1, r) :
                for x in range(1, c-1) :
                    dp[y][x] = min(dp[y-1][x-1:x+2]) + 1 if grid[y][x] else 0
                    ret += max(0, dp[y][x] - 1)

        return ret
