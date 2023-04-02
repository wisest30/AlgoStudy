#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for(auto& x : A) cin >> x;
    for(auto& x : B) cin >> x;

    map<int, int> idx;
    for(auto i = 0; i < n; ++i)
        idx[A[i]] = i;

    int odd_set = 0;
    vector<bool> visited(n);

    for(auto i = 0; i < n; ++i) {
        if(visited[i]) continue;

        auto cur = i, cnt = 0;
        while(!visited[cur]) {
            visited[cur] = true;
            cnt++;
            cur = idx[B[cur]];
        }

        if(cnt % 2)
            odd_set++;
    }

    auto p = (n - odd_set) / 2;
    ll ret = 0;
    for(auto i = 1; i <= p; ++i)
        ret -= 2 * i;
    for(auto i = n - p + 1; i <= n; ++i)
        ret += 2 * i;
    
    cout << ret << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
