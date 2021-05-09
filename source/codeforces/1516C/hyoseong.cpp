#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int n, total_sum;
vector<int> A;
vector<vector<int>> cache;

int recur(int idx, int sum) {
    if(idx == n)
        return sum * 2 == total_sum;
    
    auto& ret = cache[idx][sum];
    if(ret != -1) return ret;

    return ret = recur(idx + 1, sum) | recur(idx + 1, sum + A[idx]);
}

void solve(int TestCase) {
    cin >> n;

    total_sum = 0;
    A.resize(n);
    for(auto& x : A) {
        cin >> x;
        total_sum += x;
    }

    cache = vector<vector<int>>(n, vector<int>(200001, -1));

    bool possible = recur(0, 0);
    if(!possible) {
        cout << 0 << endl;
        return;
    }

    int g = 0;
    for(auto a : A) g = __gcd(g, a);
    for(auto& x : A) x /= g;
    for(auto i = 0; i < n; ++i) {
        if(A[i] % 2) {
            cout << 1 << endl;
            cout << (i+1) << endl;
            return;
        }
    }
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
