typedef long long ll;

class Solution {
public:
    ll dp[1'00000+5];
    vector<vector<int>> questions;
    int n;
    
    ll getDp(int idx)
    {
        if(idx >= n) return 0; 
        if(dp[idx] != -1) return dp[idx];
        
        return dp[idx] = max(questions[idx][0] + getDp(idx + questions[idx][1] + 1), getDp(idx+1));
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof(dp));
        this->questions = questions;
        n = questions.size();
        
        ll ans = 0;
        
        for(int i=0;i<n;i++) ans = max(ans, getDp(i));    
        
        return ans;
    }
};
