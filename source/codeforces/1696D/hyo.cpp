#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int solve2(vector<int>& V) {
    if(V.empty())
        return 0;

    int n = V.size(), ret = 0, type = 1;
    vector<int> mx(n, 0), mn(n, INT_MAX);
    mx[0] = mn[0] = V[0];
    for(auto i = 1; i < n; ++i)
        mx[i] = max(mx[i-1], V[i]), mn[i] = min(mn[i-1], V[i]);
    
    for(auto i = n-1; i >= 0; --i) {
        if(type == 0 && V[i] == mn[i])
            ++ret, type = 1;
        else if(type == 1 && V[i] == mx[i])
            ++ret, type = 0;
    }

    return ret;
}

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& x : A) cin >> x;

    int idx_1 = find(A.begin(), A.end(), 1) - A.begin();

    vector<int> L(A.begin(), A.begin() + idx_1);
    vector<int> R(A.begin() + idx_1 + 1, A.end());
    reverse(R.begin(), R.end());

    auto ret = solve2(L) + solve2(R);
    cout << ret << endl;
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
