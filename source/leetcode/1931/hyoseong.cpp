class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int m, n, p;
    
    int recur(int y, int x, int prev) {
        if(y == n) return 1;
        if(x == m) return recur(y+1, 0, prev);
        
        auto& ret = dp[y][x][prev];
        if(ret != -1) return ret;
        
        int left = -1, up = -1;
        if(x > 0) left = prev % 3;
        if(y > 0) up = prev / p;
        
        auto nxt = 
        ret = 0;
        for(auto color = 0; color < 3; ++color) {
            auto nxt = (prev - prev / p * p) * 3 + color;
            if(color != left && color != up)
                ret = (ret + recur(y, x + 1, nxt)) % MOD;
        }
        
        return ret;
    }
    
    int colorTheGrid(int m, int n) {
        this->m = m, this->n = n;
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(243, -1))); // 243 == 3 ^ 5
        
        this->p = 1;
        for(auto i = 0; i < m - 1; ++i)
            this->p *= 3;

        auto ret = recur(0, 0, 0);
        return ret;
    }
};
