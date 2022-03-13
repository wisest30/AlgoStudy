class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int ret = 0;
        auto A = vector<vector<bool>>(n, vector<bool>(n));
        for(auto& d : dig)
            A[d[0]][d[1]] = true;
        
        for(auto& fact : artifacts) {
            bool ok = true;
            for(auto i = fact[0]; i <= fact[2]; ++i)
                for(auto j = fact[1]; j <= fact[3]; ++j)
                    ok &= A[i][j];

            ret += ok;
        }
        
        return ret;
    }
};
