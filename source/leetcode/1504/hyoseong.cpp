class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        auto A = mat;
        for(auto i = 0; i < n; ++i)
            for(auto j = 0; j < m; ++j)
                if(i && A[i][j]) A[i][j] += A[i-1][j];
        
        auto ret = 0;
        for(auto i = 0; i < n; ++i) {
            for(auto j = 0; j < m; ++j) {
                auto min_val = INT_MAX;
                for(auto k = j; k >= 0; --k) ret += min_val = min(min_val, A[i][k]);
            }
        }
        
        return ret;
    }
};
