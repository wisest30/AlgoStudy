typedef long long ll;

class Solution {
public:
    ll dp[2][4]{};
    const ll MOD = 1e9+7;
    
    int countHousePlacements(int n) {
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++)
        {
            dp[i&1][0] = (dp[(i+1)&1][0] + dp[(i+1)&1][1] + dp[(i+1)&1][2] + dp[(i+1)&1][3])%MOD;
            dp[i&1][1] = (dp[(i+1)&1][0] + dp[(i+1)&1][2])%MOD;
            dp[i&1][2] = (dp[(i+1)&1][0] + dp[(i+1)&1][1])%MOD;
            dp[i&1][3] = dp[(i+1)&1][0]%MOD;
        }
        
        return (dp[n&1][0] + dp[n&1][1] + dp[n&1][2] + dp[n&1][3])%MOD;
    }
};
