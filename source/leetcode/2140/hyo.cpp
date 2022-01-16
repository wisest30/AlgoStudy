class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n), mdp(n);
        for(auto i = n-1; i >= 0; --i) {
            dp[i] = questions[i][0];
            if(i + 1 + questions[i][1] < n) dp[i] = max(dp[i], mdp[i + 1 + questions[i][1]] + questions[i][0]);
            mdp[i] = dp[i];
            if(i < n-1) mdp[i] = max(mdp[i], mdp[i+1]);
        }
        return mdp[0];
    }
};
