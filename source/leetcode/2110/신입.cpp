class Solution {
public:
    typedef long long ll;
    
    long long getDescentPeriods(vector<int>& prices) {
        ll ans;
        int n = prices.size();
        vector<int> dp(n, 1);
        ans = 1LL;
        
        for(int i=1;i<n;i++)
        {
            if(prices[i] == prices[i-1]-1) dp[i] = dp[i-1]+1;
            ans += dp[i];
        }
        
        return ans;
    }
};
