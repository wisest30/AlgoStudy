#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int n, k;
vector<int> A;
vector<vector<int>> G;

int get_max_val(vector<int>& a) {
    return *max_element(a.begin(), a.end());
}

void amax(int& res, int k) {
    if(k > res) res = k;
}

vector<vector<int>> dfs(int cur, int prev) {
    auto ret = vector<vector<int>>(k + 2, vector<int>(3));

    for(auto nxt : G[cur]) {
        if(nxt == prev) continue;

        auto nxt_ret = ret;
        auto sub_ret = dfs(nxt, cur);
        for(auto i = 0; i < ret.size(); ++i) {
            for(auto j = 0; j < nxt_ret.size(); ++j) {
                if(i + j == 0) continue;
                if(i + j < ret.size()) {
                    amax(nxt_ret[i + j][0], get_max_val(ret[i]) + get_max_val(sub_ret[j]));
                    if(i) amax(nxt_ret[i + j][1], ret[i][1] + get_max_val(sub_ret[j]));
                    if(j) amax(nxt_ret[i + j][1], get_max_val(ret[i]) + sub_ret[j][1]);
                }

                if(i && j && i + j - 1 < ret.size())
                    amax(nxt_ret[i + j - 1][2], ret[i][1] + sub_ret[j][1]);
            }
        }

        swap(nxt_ret, ret);
    }

    for(auto i = 1; i < ret.size(); ++i)
        ret[i][1] += A[cur], ret[i][2] += A[cur];

    return ret;
}

void solve(int TestCase) {
    cin >> n >> k;
    A.resize(n);
    for(auto& x : A) cin >> x;

    G = vector<vector<int>>(n);
    for(auto i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if(k == 0) {
        cout << A[0] << endl;
        return;
    }

    auto ret = dfs(0, -1);
    cout << ret[k][2] << endl;
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
