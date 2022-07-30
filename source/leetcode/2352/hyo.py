class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n, ret = len(grid), 0
        for i in range(n) :
            for j in range(n) :
                for k in range(n) :
                    if grid[i][k] != grid[k][j] :
                        break
                else :
                    ret += 1
        
        return ret
