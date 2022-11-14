#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, c;
    cin >> n >> c;

    vector<int> M(c + 1);
    for(auto i = 0; i < n; ++i) {
        int x;
        cin >> x;
        M[x] = 1;
    }

    vector<int> ps(M.size() + 1);
    for(auto i = 1; i < ps.size(); ++i)
        ps[i] = ps[i-1] + M[i-1];
    
    for(auto y = 1; y <= c; ++y) {
        if(!M[y]) continue;

        for(auto a = 1; a * y <= c; ++a) {
            if(!M[a] && ps[min((int)ps.size() - 1, (a + 1) * y)] - ps[a * y]) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
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
