#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 201;

int n;
// choice : best root node.
ll C[MAX_N][MAX_N], ps[MAX_N][MAX_N], dp[MAX_N][MAX_N], choice[MAX_N][MAX_N];

ll get_ps(int y0, int x0, int y1, int x1) {
    return ps[y1][x1] - ps[y0][x1] - ps[y1][x0] + ps[y0][x0];
}

// 하위 노드에서 상위 노드로 가는 비용만 고려
ll recur(int l, int r) {
    if(l == r) return 0;
    if(l + 1 == r) {
        choice[l][r] = l;
        return 0;
    }

    auto& ret = dp[l][r];
    if(ret != -1) return ret;

    ret = INT64_MAX;
    int min_root = -1;
    for(auto root = l; root < r; ++root) {
        ll candi = recur(l, root) + recur(root + 1, r);
        candi += get_ps(l, 0, root, l) + get_ps(l, root, root, n); // left nodes cost
        candi += get_ps(root + 1, 0, r, root + 1) + get_ps(root + 1, r, r, n); // right nodes cost
        if(candi < ret) {
            ret = candi;
            min_root = root;
        }
    }

    choice[l][r] = min_root;
    return ret;
}

int par[MAX_N];
void dfs(int l, int r, int prev) {
    if(l == r) return;
    int cur = choice[l][r];
    par[cur] = prev;
    dfs(l, cur, cur);
    dfs(cur + 1, r, cur);
}

void solve(int TestCase) {
    memset(ps, 0, sizeof(ps));
    memset(dp, -1, sizeof(dp));
    memset(choice, -1, sizeof(choice));
    memset(par, -1, sizeof(par));
    cin >> n;
    for(auto i = 0; i < n; ++i)
        for(auto j = 0; j < n; ++j)
            cin >> C[i][j];
    
    for(auto i = 0; i < n; ++i)
        for(auto j = 0; j < n; ++j)
            ps[i+1][j+1] = ps[i+1][j] + ps[i][j+1] - ps[i][j] + C[i][j];
    
    recur(0, n);
    dfs(0, n, -1);
    
    for(auto i = 0; i < n; ++i) cout << (par[i] + 1) << " ";
    cout << endl;
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
