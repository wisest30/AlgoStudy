#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int ans(int x) {
    cout << x << endl;
    int r;
    cin >> r;

    if(r == -1) exit(0);
    return r;
}

int k_xor(int a, int b, int k) {
    vector<int> A;
    while(a || b) {
        A.push_back((a % k + b % k) % k);
        a /= k;
        b /= k;
    }

    int ret = 0;
    reverse(A.begin(), A.end());
    for(auto x : A) ret = ret * k + x;

    return ret;
}

int inverse(int a, int k) {
    vector<int> A;
    while(a) {
        A.push_back(a % k);
        a /= k;
    }

    for(auto& x : A)
        x = (k - x) % k;
    
    int ret = 0;
    reverse(A.begin(), A.end());
    for(auto x : A) ret = ret * k + x;

    return ret;
}

void solve(int TestCase) {
    int n, k;
    cin >> n >> k;

    int p = 0;
    for(auto i = 0; i < n; ++i) {
        auto y = k_xor(i, p, k);
        if(i % 2) y = inverse(y, k);

        auto r = ans(y);
        if(r == 1) return;

        if(i % 2 == 0) p = k_xor(p, inverse(y, k), k);
        else p = k_xor(p, y, k);
    }
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
