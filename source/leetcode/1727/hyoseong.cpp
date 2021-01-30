class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        for(auto i = 1; i < r; ++i)
            for(auto j = 0; j < c; ++j)
                if(matrix[i][j])
                    matrix[i][j] += matrix[i-1][j];

        int ret = 0;
        for(auto& A : matrix) {
            sort(A.begin(), A.end(), greater<int>());
            for(auto j = 0; j < c; ++j)
                ret = max(ret, A[j] * (j+1));
        }
        
        return ret;
    }
};
