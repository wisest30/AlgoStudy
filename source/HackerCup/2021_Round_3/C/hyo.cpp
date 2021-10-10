#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int n, k;
vector<int> P;
vector<vector<int>> G;

vector<int> dfs(int cur) {
    vector<int> ret(k + 2, -1);
    ret[0] = ret[1] = 0;

    vector<vector<int>> S;
    for(auto nxt : G[cur]) {
        auto sub_ret = dfs(nxt);
        auto nxt_ret = ret;
        for(auto i = 0; i < k + 2; ++i) {
            for(auto j = 0; j < k + 2; ++j) {
                if(ret[i] == -1 || sub_ret[j] == -1) continue;
                auto h = min(i + j, k + 1);
                nxt_ret[h] = max(nxt_ret[h], ret[i] + sub_ret[j]);
            }
        }

        S.push_back(std::move(sub_ret));
        swap(ret, nxt_ret);
    }

    for(const auto& sub_ret : S)
        if(sub_ret[k + 1] != -1)
            ret[k + 1] = max(ret[k + 1], sub_ret[k + 1] + 1);
    
    if((int)S.size() >= k) {
        auto su = 0;
        for(const auto& sub_ret : S)
            if(sub_ret[k + 1] != -1) su += sub_ret[k + 1];
        
        for(const auto& sub_ret : S) {
            if(sub_ret[2] != -1) {
                auto candi = sub_ret[k + 1] == -1
                           ? su + 1
                           : su - sub_ret[k + 1] + 1;
                
                ret[k + 1] = max(ret[k + 1], candi);
            }
        }
    }

    return ret;
}

void solve(int TestCase) {
    cin >> n >> k;

    P.resize(n);
    P[0] = -1;
    for(auto i = 1; i < n; ++i) {
        cin >> P[i];
        --P[i];
    }

    G.clear();
    G.resize(n);
    for(auto i = 1; i < n; ++i)
        G[P[i]].push_back(i);
    
    auto ret = dfs(0);
    auto ans = *max_element(ret.begin(), ret.end());

    cout << ans << endl;
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
