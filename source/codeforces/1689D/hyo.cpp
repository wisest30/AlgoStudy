#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, m;
    cin >> n >> m;

    vector<string> A(n);
    for(auto& x : A) cin >> x;

    vector<vector<ll>> P(m);
    for(auto y = 0; y < n; ++y)
        for(auto x = 0; x < m; ++x)
            if(A[y][x] == 'B')
                P[x].push_back(y);
    
    ll min_max_d = INT_MAX, ret_y = -1, ret_x = -1;
    for(auto y = 0; y < n; ++y) {
        vector<ll> L(m, -INT_MAX), R(m, -INT_MAX);
        for(auto x = 0; x < m; ++x) {
            if(!P[x].empty()) {
                L[x] = R[x] = max(abs(P[x][0] - y), abs(P[x].back() - y));
                L[x] += m - x;
                R[x] += 1 + x;
            }            
        }

        vector<ll> maxL(m, -INT_MAX), maxR(m, -INT_MAX);
        maxL[0] = L[0];
        for(auto x = 1; x < m; ++x)
            maxL[x] = max(maxL[x-1], L[x]);
        maxR[m-1] = R[m-1];
        for(auto x = m-2; x >= 0; --x)
            maxR[x] = max(maxR[x+1], R[x]);
        
        for(auto x = 0; x < m; ++x) {
            ll max_d = -INT_MAX;
            max_d = max(max_d, maxL[x] - (m - x));
            max_d = max(max_d, maxR[x] - (1 + x));

            assert(max_d >= 0);
            if(max_d < min_max_d) {
                min_max_d = max_d;
                ret_y = y;
                ret_x = x;
            }
        }
    }

    cout << (ret_y + 1) << " " << (ret_x + 1) << endl;
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
