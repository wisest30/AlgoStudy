#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, q;
    cin >> n >> q;

    vector<ll> A(n);
    for(auto& a : A)
        cin >> a;
    
    sort(A.begin(), A.end());

    vector<ll> ps(n+1);
    for(auto i = 0; i < n; ++i)
        ps[i+1] = ps[i] + A[i];

    unordered_set<ll> s;
    queue<pair<int, int>> que;
    que.push({0, n});
    while(!que.empty()) {
        auto left = que.front().first;
        auto right = que.front().second;
        que.pop();
        s.insert(ps[right] - ps[left]);

        if(right - left <= 1)
            continue;

        auto min_val = A[left];
        auto max_val = A[right-1];

        if(min_val == max_val)
            continue;

        auto mid = (min_val + max_val) / 2;

        auto p = upper_bound(A.begin() + left, A.begin() + right, mid) - A.begin();
        que.push({left, p});
        que.push({p, right});
    }

    for(auto i = 0; i < q; ++i) {
        ll x;
        cin >> x;
        if(s.find(x) != s.end())
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    cout << endl;
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
