#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<int> B(n);
    for(auto& x : B) cin >> x;

    vector<array<int, 3>> S(n);
    for(auto i = 0; i < n; ++i) {
        S[i][0] = (i + 1) / (B[i] + 1) + 1;
        S[i][1] = B[i] == 0 ? n : (i + 1) / B[i];
        S[i][2] = i;
    }

    sort(S.begin(), S.end());

    vector<int> ret(n);
    priority_queue<array<int, 2>> pq;
    for(auto cur = 1, i = 0; cur <= n; ++cur) {
        while(i < n && S[i][0] == cur) {
            pq.push({-S[i][1], S[i][2]});
            ++i;
        }
        
        ret[pq.top()[1]] = cur;
        pq.pop();
    }

    for(auto x : ret) cout << x << ' ';
    cout << endl;
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
