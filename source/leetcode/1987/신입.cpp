class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int dp[2] = {0, 0};
        const int mod = 1'000'000'007;
        
        bool has0 = false;
        
        for(char ch : binary)
        {
            if(ch == '0') 
            {
                dp[0] = (dp[0] + dp[1])%mod;
                has0 = true;
            }
            else dp[1] = (dp[0] + dp[1] + 1)%mod;
        }
        
        return (dp[0] + dp[1] + (has0 ? 1 : 0))%mod;
    }
};
