class Solution {
public: 
    int n;
    vector<int> ps;
    vector<vector<int>> dp;
    
    int recur(int idx, int turn) {
        if(idx == n) return ps[n];
        
        auto& ret = dp[idx][turn];
        if(ret != -INT_MAX) return ret;
        
        if(idx <= 1) ret = recur(idx + 1, turn);
        else ret = max(ps[idx] - recur(idx + 1, turn ^ 1), recur(idx + 1, turn));
        return ret;
    }
    
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        ps = vector<int>(n+1);
        for(auto i = 1; i <= n; ++i)
            ps[i] = ps[i-1] + stones[i-1];
        
        dp = vector<vector<int>>(n, vector<int>(2, -INT_MAX));
        auto ret = recur(0, 0);
        return ret;
    }
};
