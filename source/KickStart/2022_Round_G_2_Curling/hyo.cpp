#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
void solve(int TestCase) {
    int s, h;
    cin >> s >> h;

    vector<pair<int, int>> A;
    int n;
    cin >> n;
    for(auto i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        int d = x * x + y * y;

        if(d <= (s + h) * (s + h)) A.push_back({d, 0});
    }

    int m;
    cin >> m;
    for(auto i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        int d = x * x + y * y;
        if(d <= (s + h) * (s + h)) A.push_back({d, 1});
    }

    sort(A.begin(), A.end());

    vector<int> ret(2);
    for(auto& p : A) {
        if(ret[p.second ^ 1]) break;
        ret[p.second]++;
    }

    cout << ret[0] << " " << ret[1] << endl;
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
