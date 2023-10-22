#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int TestCase)
{
    int r, c;
    cin >> r >> c;
    vector<string> A(r);
    for (auto &x : A)
        cin >> x;

    int dy[4] = {-1, 0, 0, 1};
    int dx[4] = {0, -1, 1, 0};
    vector<vector<bool>> visited(r, vector<bool>(c));
    int empty_y = -1, empty_x = -1;
    function<int(int, int)> dfs = [&](int y, int x)
    {
        int cnt = 1;
        visited[y][x] = true;
        for (auto i = 0; i < 4; ++i)
        {
            auto ny = y + dy[i];
            auto nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                continue;
            if (visited[ny][nx])
                continue;
            if (A[ny][nx] == 'B')
                continue;
            if (A[ny][nx] == '.')
            {
                // cout << "debug00 " << empty_y << " " << empty_x << " " << ny << " " << nx << endl;
                if (empty_y == -1)
                {
                    empty_y = ny;
                    empty_x = nx;
                }
                else if (empty_y != -2 && (empty_y != ny || empty_x != nx))
                {
                    empty_y = -2;
                    empty_x = -2;
                }

                continue;
            }
            cnt += dfs(ny, nx);
        }

        // cout << cnt << " " << empty_cnt << " " << empty_y << " " << empty_x << " " << y << " " << x << endl;
        return cnt;
    };

    for (auto y = 0; y < r; ++y)
    {
        for (auto x = 0; x < c; ++x)
        {
            if (A[y][x] != 'W')
                continue;
            if (visited[y][x])
                continue;

            empty_y = -1, empty_x = -1;
            auto ret = dfs(y, x);
            // cout << ret << " " << empty_y << " " << empty_x << endl;
            if (empty_y >= 0)
            {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (auto i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve(i);
    }
}
