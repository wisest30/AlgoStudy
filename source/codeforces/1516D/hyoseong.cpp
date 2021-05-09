#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

vector<int> get_factors(int n) {
    auto ret = vector<int>{};
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.push_back(i);
            while(n % i == 0) n /= i;
        }
    }

    if(n != 1) ret.push_back(n);

    return ret;
}

constexpr int MAX_A = 100000;
void solve(int TestCase) {
    int n, q;
    cin >> n >> q;

    vector<int> A(n);
    for(auto& x : A) cin >> x;

    auto last_idx = vector<int>(MAX_A + 1, n);
    auto jump = vector<vector<int>>(32, vector<int>(n, n));
    for(auto i = n-1; i >= 0; --i) {
        auto factors = get_factors(A[i]);
        for(auto f : factors) {
            jump[0][i] = min(jump[0][i], last_idx[f]);
            last_idx[f] = i;
        }

        if(i < n-1)
            jump[0][i] = min(jump[0][i], jump[0][i+1]);
    }

    for(auto i = 1; i < jump.size(); ++i)
        for(auto j = 0; j < n; ++j)
            if(jump[i-1][j] < n)
                jump[i][j] = jump[i-1][jump[i-1][j]];

    for(auto i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--;

        int ret = 1;
        while(l < r) {
            if(jump[0][l] >= r) break;

            for(auto i = 31; i >= 0; --i) {
                if(jump[i][l] < r) {
                    l = jump[i][l];
                    ret += 1 << i;
                    break;
                }
            }
        }

        cout << ret << endl;
    }
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
