#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int swap_cnt(vector<int> A, int k) {
    rotate(A.begin(), A.begin() + k, A.end());

    int ret = 0;
    for(auto i = 0; i < A.size(); ++i)
        while(A[i] != i+1)
            swap(A[i], A[A[i] - 1]), ret++;

    return ret;
}

void solve(int TestCase) {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for(auto& x : A) cin >> x;
    
    map<int, int> cnt;
    set<int> candies;
    for(auto i = 0; i < n; ++i) {
        auto p = (i - (A[i] - 1) + n) % n;
        cnt[p]++;
        if(cnt[p] >= n / 3)
            candies.insert(p);
    }

    vector<int> ret;
    for(auto p : candies)
        if(swap_cnt(A, p) <= m) ret.push_back(p);

    cout << ret.size() << " ";
    for(auto x : ret) cout << x << " ";
    cout << '\n';
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
