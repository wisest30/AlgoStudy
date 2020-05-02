class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        int dp[52][51][101];
        int mod = 1000000007;
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        
        for(int i=1;i<=n;++i)
        {
            for(int mx_len=0;mx_len<i;++mx_len)
            {
                for(int mx=0;mx<=m;++mx)
                {
                    for(int new_mx = mx+1;new_mx<=m;++new_mx) dp[i][mx_len+1][new_mx] = (dp[i][mx_len+1][new_mx] + dp[i-1][mx_len][mx])%mod;
                    for(int less_mx = 1;less_mx<=mx;++less_mx) dp[i][mx_len][mx] = (dp[i][mx_len][mx] + dp[i-1][mx_len][mx])%mod;
                }
            }
        }
        
        int ans = 0;
        for(int i=1;i<=m;++i) ans = (ans + dp[n][k][i])%mod;
        return ans;
    }
};
