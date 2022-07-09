class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9+7;
        int dp[1000+5]{};
        
        dp[1] = 1;
        
        int share = 0;
        
        for(int i=2;i<=n;i++)
        {
            if(i >= delay) share = (share + dp[i-delay])%MOD;
            if(i >= forget) share = (share + MOD - dp[i-forget])%MOD;
            dp[i] = share;
        }
        
        int ans = 0;
        
        for(int i=n-forget+1;i<=n;i++) ans = (ans + dp[i])%MOD;
        
        return ans;
    }
};
