class Solution {
public:
    int n;
    vector<int> A;
    vector<vector<int>> dp;
    
    int recur(int x, int y) {
        if(x == n) return 0;
        if(A[x] - 1 == y) return INT_MAX;
        
        auto& ret = dp[x][y];
        if(ret != -1) return ret;
        
        ret = INT_MAX;
        for(auto i = 0; i < 3; ++i) {
            auto candi = recur(x+1, i);

            if(candi == INT_MAX) continue;
            if(A[x] - 1 == i) continue;
            
            if(y != i) candi++;
            
            ret = min(ret, candi);
        }
        return ret;
    }
    
    int minSideJumps(vector<int>& A) {        
        this->n = (int)A.size() - 1;
        this->A = A;
        this->dp = vector<vector<int>>(n+1, vector<int>(3, -1));
        
        auto ret = recur(0, 1);
        
        return ret;
    }
};
