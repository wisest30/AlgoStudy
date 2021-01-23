class Solution {
public:   
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
       
        auto dp = vector<vector<int>>(1 << n, vector<int>(k+1, INT_MAX));
        for(auto subset = 0; subset < dp.size(); ++subset) {
            dp[subset][1] = 0;
            for(auto i = 0; i < n; ++i)
                if(subset & (1 << i))
                    dp[subset][1] += jobs[i];
        }
        
        for(auto j = 2; j <= k; ++j)
            for(auto i = 0; i < (1 << n); ++i)
                for(auto i1 = i;; i1=(i1 - 1) & i) {
                    auto i2 = i - i1;
                    auto candi = max(dp[i1][j-1], dp[i2][1]);
                    dp[i][j] = min(dp[i][j], candi);
                    if(!i1) break;
                }
        
        return dp[(1 << n) - 1][k];
    }
};
