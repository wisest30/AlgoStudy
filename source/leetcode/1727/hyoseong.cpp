class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        auto A = vector<vector<int>>(r, vector<int>(c));
        for(auto i = 0; i < r; ++i)
            for(auto j = 0; j < c; ++j)
                if(matrix[i][j])
                    A[i][j] = (i == 0 ? 0 : A[i-1][j]) + matrix[i][j];
        
        int ret = 0;
        for(auto i = 0; i < r; ++i) {
            sort(A[i].begin(), A[i].end(), greater<int>());
            for(auto j = 0; j < c; ++j)
                ret = max(ret, (j+1) * A[i][j]);
        }
        
        return ret;
    }
};
