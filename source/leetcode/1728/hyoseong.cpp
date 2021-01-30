constexpr int MAX_TURN = 128;
constexpr int dy[4] = {-1, 0, 0, 1};
constexpr int dx[4] = {0, -1, 1, 0};

char dp[8 * 8 * 8 * 8 * MAX_TURN];

class Solution {
public:
    int r, c, my, mx, cy, cx, fy, fx;
    int catJump, mouseJump;
    vector<string> grid;
    
    char recur(int my, int mx, int cy, int cx, int turn) {
        int status = turn % 2;

        if(turn == MAX_TURN) return status;

        auto key = ((my * c + mx) * r * c + cy * c + cx) * MAX_TURN + turn;
        char& ret = dp[key];
        if(ret != -1) return ret;

        ret = 0;
        int y = status ? cy : my;
        int x = status ? cx : mx;
        int max_l = status ? catJump : mouseJump;
        for(auto i = 0; i < 4; ++i) {
            for(auto l = 0; l <= max_l; ++l) {
                int ny = y + dy[i] * l;
                int nx = x + dx[i] * l;
                
                if(ny < 0 || ny >= r || nx < 0 || nx >= c || grid[ny][nx] == '#') break;

                if(ny == fy && nx == fx) ret |= 1;
                else if(status && ny == my && nx == mx) ret |= 1;
                else if(!status && ny == cy && nx == cx) continue;
                else ret |= 1 ^ (status ? recur(my, mx, ny, nx, turn + 1) : recur(ny, nx, cy, cx, turn + 1));
                if(ret) return ret;
            }
            if(ret) return ret;
        }

        return ret;
    }
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        this->r = grid.size(); this->c = grid[0].size();
        this->catJump = catJump;
        this->mouseJump = mouseJump;
        this->grid = grid;
        memset(dp, -1, sizeof(dp));

        for(auto i = 0; i < r; ++i)
            for(auto j = 0; j < c; ++j)
                if(grid[i][j] == 'F')
                    fy = i, fx = j;
                else if(grid[i][j] == 'M')
                    my = i, mx = j;
                else if(grid[i][j] == 'C')
                    cy = i, cx = j;

        return recur(my, mx, cy, cx, 0);
    }
};
