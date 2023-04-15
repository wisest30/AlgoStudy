#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    auto odd_cnt = count(s.begin(), s.end(), '1');
    if(odd_cnt == 0 || odd_cnt % 2 == 1) {
        cout << "NO" << endl;
        return;
    }

    vector<pair<int, int>> edges;
    auto root = s.find("10") + 1;
    auto i = (root + 1) % n;
    while(i != root) {
        edges.push_back({root, i});

        auto j = i;
        while(s[j] != '1') {
            edges.push_back({j, (j+1) % n});
            j = (j+1) % n;
        }

        i = (j+1) % n;
    }

    cout << "YES" << endl;
    for(auto& e : edges)
        cout << (e.first+1) << " " << (e.second+1) << endl;
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
