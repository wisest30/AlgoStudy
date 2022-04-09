#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int f(const string& from, const string& to) {
    int n = min(from.size(), to.size());
    int ret = from.size() + to.size();
    for(auto i = 0; i < n; ++i) {
        if(from[i] == to[i])
            ret -= 2;
        else
            break;
    }

    return ret;
}

void solve(int TestCase) {
    int e, w;
    cin >> e >> w;

    vector<pair<int, string>> P;
    P.push_back({0, ""});
    for(auto i = 0; i < e; ++i) {
        string A;
        for(auto j = 0; j < w; ++j) {
            int cnt;
            cin >> cnt;
            for(auto k = 0; k < cnt; ++k)
                A.push_back('0' + j);
        }

        vector<pair<int, string>> nxt_P;
        do {
            int min_v = INT_MAX;
            for(auto& p : P) {
                min_v = min(min_v, p.first + f(p.second, A));
            }

            nxt_P.push_back({min_v, A});
        } while (next_permutation(A.begin(), A.end()));

        swap(P, nxt_P);
    }

    int min_v = INT_MAX;
    for(auto& p : P)
        min_v = min(min_v, p.first + (int)p.second.size());
    
    cout << min_v << "\n";
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
