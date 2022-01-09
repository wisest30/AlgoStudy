class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(auto i = 0; i < n; ++i) {
            set<int> a, b;
            for(auto j = 0; j < n; ++j) a.insert(matrix[i][j]), b.insert(matrix[j][i]);
            if(a.size() != n || b.size() != n) return false;
        }
        return true;
    }
};
