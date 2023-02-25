#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    constexpr int MOD = 998244353;
    function<pair<ll, string>(int)> dfs = [&](int cur) {
        auto c = s[cur - 1];

        if(2 * cur - 1 >= s.size())
            return make_pair(1ll, string(1, c));

        auto left = dfs(2 * cur);
        auto right = dfs(2 * cur + 1);
        if(left.second > right.second)
            swap(left, right);

        if (left.second == right.second)
            return make_pair(left.first * right.first % MOD,
                            string(1, c) + left.second + right.second);
        else
            return make_pair(left.first * right.first % MOD * 2 % MOD,
                            string(1, c) + left.second + right.second);

    };

    auto ret = dfs(1).first;
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
