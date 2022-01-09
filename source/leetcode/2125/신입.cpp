class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int R = bank.size();
        int C = bank[0].size();
        
        int ans = 0;
        
        int before = 0;
        
        for(int i=0;i<R;i++)
        {
            int cur = 0;
            
            for(int j=0;j<C;j++)
            {
                if(bank[i][j] == '1') cur++;    
            }
            
            ans += before * cur;
            
            if(cur) before = cur;
        }
        
        return ans;
    }
};
