typedef long long ll;

class Solution {
public:
    const ll MOD = 1e9+7;
    
    int countTexts(string pressedKeys) {
        ll dp[1'00000+5]{};
        dp[0] = 1;
        int n = pressedKeys.size();
        
        for(int i=1;i<=n;i++)
        {
            if(i-1 >= 0) dp[i] += dp[i-1];
            if(i-2 >= 0) 
            {
                string substr = pressedKeys.substr(i-2, 2);
                if(substr[0] == substr[1]) dp[i] += dp[i-2];
            }
            if(i-3 >= 0) 
            {
                string substr = pressedKeys.substr(i-3, 3);
                if(substr[0] == substr[1] && substr[1] == substr[2]) dp[i] += dp[i-3];
            }
            if(i-4 >= 0)
            {
                string substr = pressedKeys.substr(i-4, 4);
                if(substr == "9999" || substr == "7777") dp[i] += dp[i-4];
            }
            
            dp[i] %= MOD;
            
            //cout << dp[i] << "\n";
        }
        
        return dp[n];
    }
};
