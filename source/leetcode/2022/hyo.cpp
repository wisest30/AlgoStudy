class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz = original.size();
        if(m * n != sz) return {};
        
        auto ret = vector<vector<int>>(m, vector<int>(n));
        for(auto i = 0; i < sz; ++i) {
            ret[i / n][i % n] = original[i];
        }
        
        return ret;
    }
};
