class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26);
        
        for(auto c : s) {
            int max_len = 0;
            for(auto i = 0; i < 26; ++i) {
                if(abs(i - (c - 'a')) <= k)
                    max_len = max(max_len, dp[i] + 1);
            }
            
            dp[c - 'a'] = max_len;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
