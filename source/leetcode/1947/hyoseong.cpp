class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& S, vector<vector<int>>& M) {
        int m = S.size(), n = S[0].size();
        vector<int> A(m);
        iota(A.begin(), A.end(), 0);

        int ret = 0;
        do {
            int candi = 0;
            for(auto i = 0; i < m; ++i)
                for(auto j = 0; j < n; ++j)
                    if(S[i][j] == M[A[i]][j])
                        candi++;
            ret = max(ret, candi);
    	} while (next_permutation(A.begin(), A.end()));
        
        return ret;
    }
};
