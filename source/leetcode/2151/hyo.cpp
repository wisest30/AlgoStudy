class Solution {
public:
    int maximumGood(vector<vector<int>>& A) {
        int n = A.size(), ret = 0;
        for(auto subset = 0; subset < (1 << n); ++subset) {
            bool ans = true;
            for(auto i = 0; i < n; ++i) {
                if(subset & (1 << i))
                    for(auto j = 0; j < n; ++j)
                        if(!A[i][j] && (subset & (1 << j)) || A[i][j] == 1 && !(subset & (1 << j)))
                            ans = false;
                if(!ans)
                    break;
            }
            if(ans)
                ret = max(ret, __builtin_popcount(subset));
        }
        return ret;
    }
};
