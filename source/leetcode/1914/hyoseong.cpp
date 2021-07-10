class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size(), c = grid[0].size();
               
        auto visitFunc = [&](auto sy, auto sx, function<void(int, int)>& func) {
            int i = sy, j = sx;
            while(i < r - sy) func(i++, j);
            --i, ++j;

            while(j < c - sx) func(i, j++);
            --j, --i;
            
            while(i >= sy) func(i--, j);
            ++i, --j;
            
            while(j > sx) func(i, j--);
        };
        
        for(int sy = 0, sx = 0; sy < r / 2 && sx < c / 2; ++sy, ++sx) {
            vector<int> A, B;
            function<void(int, int)> getter = [&](auto i, auto j) {
                A.push_back(grid[i][j]);
            };
            
            visitFunc(sy, sx, getter);
            
            int kk = k % A.size();
            B.resize(A.size());
            for(auto i = 0; i < A.size(); ++i)
                B[(i + kk) % A.size()] = A[i];            
            
            int k = 0;
            function<void(int, int)> setter = [&](auto i, auto j) {
                grid[i][j] = B[k++];
            };
            
            visitFunc(sy, sx, setter);
        }
        
        return grid;
    }
};
