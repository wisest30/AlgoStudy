#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

int f1(int a, int b) {
    if(a > b) swap(a, b);
    if(a * 2 <= b) return (b + 1) / 2;
    return (a + b + 2) / 3;
}

int f2(int a, int b) {
    return (a + b + 1) / 2;
}

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& a : A) cin >> a;

    auto ret = INT_MAX;
    for(auto i = 0; i < n; ++i) {
        if(i + 1 < n)
            ret = min(ret, f1(A[i], A[i+1]));
        if(i + 2 < n)
            ret = min(ret, f2(A[i], A[i+2]));
    }

    sort(A.begin(), A.end());
    ret = min(ret, (A[0] + 1) / 2 + (A[1] + 1) / 2);

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
