class Solution:
    def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
        r, c = len(grid), len(grid[0])
        Cost = [grid[0]] + [[float('inf')] * c for _ in range(r-1)]
        for x in range(r - 1) :
            for y in range(c) :
                for ny in range(c) :
                    Cost[x+1][ny] = min(Cost[x+1][ny], Cost[x][y] + grid[x+1][ny] + moveCost[grid[x][y]][ny])

        return min(Cost[-1])
                
