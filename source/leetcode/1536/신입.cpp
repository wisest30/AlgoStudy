class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        
        vector<int> rightMostOne(R, -1);
        
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(grid[i][j] == 1) rightMostOne[i] = j;
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<R;i++)
        {
            if(rightMostOne[i] <= i) continue;
            
            bool find = false;
            int j;
            
            for(j=i+1;j<R;j++)
            {
                if(rightMostOne[j] <= i)
                {
                    find = true;
                    break;
                }
            }
            
            if(!find) return -1;
            
            for(;j>i;j--) 
            {
                swap(rightMostOne[j], rightMostOne[j-1]);
                ans++;
            }
        }
        
        return ans;
    }
};
