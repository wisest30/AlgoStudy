class Solution {
public:
    static constexpr int dy[4] = {-1, 0, 0, 1};
    static constexpr int dx[4] = {0, -1, 1, 0};
    vector<vector<int>> grid1, grid2;
    int m, n;
    
    bool dfs(int y, int x, vector<vector<bool>>& visited) {
        if(visited[y][x])
            return true;
        visited[y][x] = true;
        
        auto ret = true;
        if(grid1[y][x] == 0)
            ret = false;
        
        for(auto i = 0; i < 4; ++i) {
            auto ny = y + dy[i];
            auto nx = x + dx[i];
            if(ny < 0 || ny >= m || nx < 0 || nx >= n)
                continue;
            if(grid2[ny][nx] == 0)
                continue;
            if(grid1[ny][nx] == 0)
                ret = false;
            ret &= dfs(ny, nx, visited);
        }
        
        return ret;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        this->grid1 = grid1, this->grid2 = grid2;
        this->m = grid1.size(), this->n = grid1[0].size();
        
        auto ret = 0;
        auto visited = vector<vector<bool>>(m, vector<bool>(n));
        for(auto y = 0; y < m; ++y)
            for(auto x = 0; x < n; ++x)
                if(!visited[y][x] && grid2[y][x])
                    ret += dfs(y, x, visited);
        
        return ret;
    }
};
