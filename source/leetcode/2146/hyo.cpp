class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n = grid.size(), m = grid[0].size();
        auto D = vector<vector<int>>(n, vector<int>(m, -1));
        constexpr int dy[4] = {-1, 0, 0, 1};
        constexpr int dx[4] = {0, -1, 1, 0};
        queue<array<int, 3>> q;
        q.push({start[0], start[1], 0});
        while(!q.empty()) {
            auto [y, x, d] = q.front();
            q.pop();
            if(D[y][x] != -1) continue;
            D[y][x] = d;
            for(auto i = 0; i < 4; ++i) {
                auto ny = y + dy[i], nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || grid[ny][nx] == 0) continue;
                q.push({ny, nx, d+1});
            }
        }
        
        vector<array<int, 4>> order;
        for(auto y = 0; y < n; ++y)
            for(auto x = 0; x < m; ++x) 
                if(D[y][x] != -1)
                    order.push_back({D[y][x], grid[y][x], y, x});

        sort(order.begin(), order.end());
        vector<vector<int>> ret;
        for(auto& o : order)
            if(o[1] >= pricing[0] && o[1] <= pricing[1] && ret.size() < k)
                ret.push_back({o[2], o[3]});

        return ret;
    }
};
