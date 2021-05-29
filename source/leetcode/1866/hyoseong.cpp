class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int n, k;
    vector<vector<long long>> dp;
    
    long long recur(int total, int visible) {
        if(total == n) return visible == k;
        
        auto& ret = dp[total][visible];
        if(ret != -1) return ret;
        
        ret = recur(total + 1, visible) * total % MOD;
        if(visible + 1 <= k)
            ret = (ret + recur(total + 1, visible + 1)) % MOD;
        
        return ret;
    }
    
    int rearrangeSticks(int n, int k) {
        this->n = n, this->k = k;
        dp = vector<vector<long long>>(n+1, vector<long long>(n+1, -1));
        
        auto ret = recur(0, 0);
        return ret;
    }
};
