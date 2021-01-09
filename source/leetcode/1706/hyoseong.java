class Solution {
    public int[] findBall(int[][] grid) {
        int[] ret = new int[grid[0].length];
        
        for(int i = 0; i < ret.length; ++i) {
            int cur = i;
            for(int r = 0; r < grid.length; ++r) {
                if(grid[r][cur] == 1 && (cur == grid[r].length - 1 || grid[r][cur+1] == -1)) {
                    cur = -1;
                    break;
                }
                else if(grid[r][cur] == -1 && (cur == 0 || grid[r][cur-1] == 1)) {
                    cur = -1;
                    break;
                }
                else
                    cur += grid[r][cur];
            }
            
            ret[i] = cur;
        }
        
        return ret;
    }
}
