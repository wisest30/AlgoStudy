class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size(), m = students[0].size();
        vector<int> S(n), M(n);
        for(auto i = 0; i < n; ++i) {
            for(auto j = 0; j < m; ++j) {
                S[i] = S[i] * 2 + students[i][j];
                M[i] = M[i] * 2 + mentors[i][j];
            }
        }
        
        vector<int> A(n);
        iota(A.begin(), A.end(), 0);

        int ret = 0;
        do {
            int candi = 0;
            for(auto i = 0; i < n; ++i) {
                auto j = A[i];
                candi += m - __builtin_popcount(S[i] ^ M[j]);
            }

            ret = max(ret, candi);
    	} while (next_permutation(A.begin(), A.end()));
        
        return ret;
    }
};
