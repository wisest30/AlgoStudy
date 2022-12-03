#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    constexpr int None = INT_MAX;
    constexpr int dx[4] = {0, -1, 1, 0};
    constexpr int dy[4] = {-1, 0, 0, 1};

    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    for(auto& p : A) cin >> p.first >> p.second;

    map<pair<int, int>, int> M;
    for(auto i = 0; i < n; ++i)
        M[A[i]] = i;

    vector<pair<int, int>> ret(n, {None, None});
    queue<int> q;
    for(auto i = 0; i < n; ++i) {
        for(auto j = 0; j < 4; ++j) {
            auto x = A[i].first + dx[j];
            auto y = A[i].second + dy[j];
            if(!M.count({x, y}))
                ret[i] = make_pair(x, y), q.push(i);
        }
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(auto i = 0; i < 4; ++i) {
            auto nx = A[cur].first + dx[i];
            auto ny = A[cur].second + dy[i];

            if(M.count({nx, ny})) {
                auto nxt = M[{nx, ny}];
                if(ret[nxt].first == None) 
                    ret[nxt] = ret[cur], q.push(nxt);
            }
        }
    }

    for(auto& p : ret)
        cout << p.first << " " << p.second << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
