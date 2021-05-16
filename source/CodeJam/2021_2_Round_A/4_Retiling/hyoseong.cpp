#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

#include<bits/stdc++.h>
 
using namespace std;

 int r, c, f, s;
vector<string> A, B;

int dfs(int y, int x) {
    if(y == r) return 0;
    if(x == c) return dfs(y+1, 0);
    if(A[y][x] == B[y][x]) return dfs(y, x+1);

    bool match_right = x + 1 < c && A[y][x+1] != B[y][x+1] && A[y][x] != A[y][x+1];
    bool match_down = y + 1 < r && A[y+1][x] != B[y+1][x] && A[y][x] != A[y+1][x];
   
    if(!match_right && !match_down)
        return dfs(y, x+1) + 1;

    int ret = INT_MAX;
    if(match_right) {
        swap(A[y][x], A[y][x+1]);
        ret = min(ret, dfs(y, x+1) + 1);
        swap(A[y][x], A[y][x+1]);
    }

    if(match_down) {
        swap(A[y][x], A[y+1][x]);
        ret = min(ret, dfs(y, x+1) + 1);
        swap(A[y][x], A[y+1][x]);
    }
        
    return ret;
}

void solve(int TestCase) {
    cin >> r >> c >> f >> s;
    if(f != 1 || s != 1) exit(0); // onley small set.

    A.resize(r), B.resize(r);
    for(auto& x : A) cin >> x;
    for(auto& x : B) cin >> x;

    auto ret = dfs(0, 0);
    cout << ret << endl;
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
