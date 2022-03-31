class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int dp[2000+5];
        int newDp[2000+5];
        
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        
        for(auto &pile : piles)
        {
            int cnt = 0;
            int sum = 0;
            
            memcpy(newDp, dp, sizeof(dp));
            
            for(int coin : pile)
            {
                sum += coin;
                cnt++;
                
                if(cnt > k) break;
                
                for(int i=k;i>=0;--i)
                {
                    if(i-cnt < 0) break;
                    if(i-cnt >= 0 && dp[i-cnt] != -1) newDp[i] = max(newDp[i], dp[i-cnt] + sum);
                }
            }
            
            memcpy(dp, newDp, sizeof(newDp));
        }
        
        return dp[k];
    }
};
