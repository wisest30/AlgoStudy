class Solution {
public:
    vector<vector<int>> getRightRotated(const vector<vector<int>>& mat) {
        int n = mat.size();
        
        auto ret = vector<vector<int>>(n, vector<int>(n));
        for(auto i = 0; i < n; ++i)
            for(auto j = 0; j < n; ++j)
                ret[j][n - 1 - i] = mat[i][j];

        return ret;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(auto i = 0; i < 4; ++i) {
            if(mat == target)
                return true;

            mat = getRightRotated(mat);
        }
        
        return false;
    }
};
