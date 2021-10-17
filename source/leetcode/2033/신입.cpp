class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // 먼저 x로 나눈 나머지가 다 같아야 함.
        int R = grid.size();
        int C = grid[0].size();
        int targetR = grid[0][0]%x;
        vector<int> newVec;
        
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(grid[i][j]%x != targetR) return -1;
                grid[i][j] -= targetR;
                grid[i][j] /= x;
                
                newVec.push_back(grid[i][j]);
            }
        }
        
        sort(newVec.begin(), newVec.end());
        int median = newVec[newVec.size()/2];
        int ans = 0;
        
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++) ans += abs(grid[i][j]-median);
        }
        
        return ans;
    }
};
