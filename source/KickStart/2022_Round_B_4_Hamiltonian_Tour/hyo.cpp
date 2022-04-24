#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

vector<string> A;
vector<vector<bool>> visited;
string ret;
int r, c;
void dfs(int y, int x, int ry, int rx, int py, int px) {
    const int dy[4] = {-1, 0, 0, 1};
    const int dx[4] = {0, -1, 1, 0};
    visited[y][x] = true;
    auto is_visited = [&](auto ny, auto nx) {
        if(ny < 0 || ny >= r || nx < 0 || nx >= c) return true;
        if(visited[ny][nx]) return true;
        if(A[ny][nx] == '#') return true;
        return false;
    };
    int cnt = 1;
    while(cnt < 4) {
        if(ry == 0 && !is_visited(y - 1, x)) {
            ret.push_back('N');
            dfs(y-1, x, 1, rx, y, x);
            ret.push_back('S');
            rx ^= 1;
            ++cnt;
        } else if(ry == 1 && !is_visited(y + 1, x)) {
            ret.push_back('S');
            dfs(y+1, x, 0, rx, y, x);
            ret.push_back('N');
            rx ^= 1;
            ++cnt;
        } else if(rx == 0 && !is_visited(y, x-1)) {
            ret.push_back('W');
            dfs(y, x-1, ry, 1, y, x);
            ret.push_back('E');
            ry ^= 1;
            ++cnt;
        } else if(rx == 1 && !is_visited(y, x+1)) {
            ret.push_back('E');
            dfs(y, x+1, ry, 0, y, x);
            ret.push_back('W');
            ry ^= 1;
            ++cnt;
        } else if(ry == 0 && rx == 0) {
            ret.push_back('S');
            ry = 1;
            ++cnt;
        } else if(ry == 1 && rx == 0) {
            ret.push_back('E');
            rx = 1;
            ++cnt;
        } else if(ry == 0 && rx == 1) {
            ret.push_back('W');
            rx = 0;
            ++cnt;
        } else if(ry == 1 && rx == 1) {
            ret.push_back('N');
            ry = 0;
            ++cnt;
        }
    };

    if(y == 0 && x == 0) {
        ret.push_back('W');
    }
}

void solve(int TestCase) {
    ret.clear();
    cin >> r >> c;

    A = vector<string>(r);
    for(auto& s : A) cin >> s;

    visited = vector<vector<bool>>(r, vector<bool>(c));
    dfs(0, 0, 0, 0, -1, 0);
    for(auto y = 0; y < r; ++y) {
        for(auto x = 0; x < c; ++x) {
            if(!visited[y][x] && A[y][x] == '*') {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }

    cout << ret << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}

