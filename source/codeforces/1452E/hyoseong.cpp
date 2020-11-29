#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 2000 + 5;
int n, m, k, L[MAX_N], R[MAX_N], F[MAX_N];
int inter(int l1, int r1, int l2, int r2) {
    if(r1 < l2 || r2 < l1) return 0;
    return min(r1, r2) - max(l1, l2) + 1;
}
void solve(int TestCase) {
    cin >> n >> m >> k;
    for(auto i = 0; i < m; ++i) cin >> L[i] >> R[i];

    int ret = 0;
    for(auto e1 = 1; e1 <= n; ++e1) {
        int candi = 0;
        memset(F, 0, sizeof(F));
        for(auto i = 0; i < m; ++i) {
            auto add = inter(L[i], R[i], e1, e1 + k - 1);
            candi += add;
            if(e1 + k - 1 < R[i] && add < k) {
                F[R[i] - add]++;
                F[L[i] - 1]--;
                if(R[i] - k >= 0)
                    F[R[i] - k]--;
                if(L[i] - k - 1 >= 0)
                    F[L[i] - k - 1]++;
            }
        }

        ret = max(ret, candi);
        auto add = 0;
        for(auto e2 = n; e2 > e1; --e2) {
            add += F[e2];
            candi += add;
            ret = max(ret, candi);
            //cout << "debug " << e1 << " " << e2 << " " << add << " " << F[e2] << endl;
        }
    }

    cout << ret << endl;
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
