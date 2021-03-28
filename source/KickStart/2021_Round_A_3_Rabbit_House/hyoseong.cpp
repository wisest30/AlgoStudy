#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int r, c;
    cin >> r >> c;

    auto A = vector<vector<int>>(r, vector<int>(c));
    for(auto i = 0; i < r; ++i)
        for(auto j = 0; j < c; ++j)
            cin >> A[i][j];

    priority_queue<array<int, 3>> q;
    for(auto i = 0; i < r; ++i)
        for(auto j = 0; j < c; ++j)
            q.push({A[i][j], i, j});
    
    long long ret = 0;
    while(!q.empty()) {
        auto t = q.top();
        q.pop();
        int a = t[0], i = t[1], j = t[2];
        if(a != A[i][j]) continue;

        if(i > 0 && A[i-1][j] < a - 1) {
            ret += a - 1 - A[i-1][j];
            A[i-1][j] = a-1;
            q.push({a-1, i-1, j});
        }
        if(j > 0 && A[i][j-1] < a - 1) {
            ret += a - 1 - A[i][j-1];
            A[i][j-1] = a-1;
            q.push({a-1, i, j-1});
        }
        if(i < r-1 && A[i+1][j] < a - 1) {
            ret += a - 1 - A[i+1][j];
            A[i+1][j] = a-1;
            q.push({a-1, i+1, j});
        }
        if(j < c-1 && A[i][j+1] < a - 1) {
            ret += a - 1 - A[i][j+1];
            A[i][j+1] = a-1;
            q.push({a-1, i, j+1});
        }
    }

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
