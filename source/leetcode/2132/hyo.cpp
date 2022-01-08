class Solution {
public:
    class PSum2 {
        using T = long long;
        vector<vector<T>> ps;
        int row, col;
    public :
        template<typename U>
        PSum2(const vector<vector<U>>& A)
        : row(A.size())
        , col(A.empty() ? 0 : A[0].size())
        {
            ps = vector<vector<T>>(row + 1, vector<T>(col + 1));
            for(auto i = 1; i <= row; ++i)
                for(auto j = 1; j <= col; ++j)
                    ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + A[i-1][j-1];
        }

        T get(int y0, int x0, int y1, int x1) {
            return ps[y1][x1] - ps[y0][x1] - ps[y1][x0] + ps[y0][x0];
        }
    };

    bool possibleToStamp(vector<vector<int>>& A, int h, int w) {
        int n = A.size(), m = A[0].size();
        PSum2 ps(A);
        auto B = vector<vector<int>>(n, vector<int>(m));
        for(auto y = 0; y < n; ++y) for(auto x = 0; x < m; ++x)
            if(!A[y][x] && y + h <= n && x + w <= m && !ps.get(y, x, y+h, x+w)) 
                B[y][x] = 1;

        PSum2 ps2(B);
        for(auto y = 0; y < n; ++y) for(auto x = 0; x < m; ++x)
            if(!A[y][x] && ps2.get(max(0, y+1-h), max(0, x+1-w), y+1, x+1) == 0)
                return false;

        return true;
    }
};
