class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int r = grid.size(), c = grid[0].size();
        
        vector<int> A;
        for(auto y = 0; y < r; ++y) for(auto x = 0; x < c; ++x) A.push_back(grid[y][x]);
        sort(A.begin(), A.end());
        
        int n = A.size();
        int m = n / 2;
        
        long long ret = 0;
        for(auto i = 0; i < n; ++i) {
            if(A[i] % x != A[0] % x) return -1;
            ret += abs(A[m] - A[i]) / x;
        }
        
        return ret;
    }
};
