#include<bits/stdc++.h>
 
using namespace std;

constexpr int MAX_N = 5001;
int n;
vector<long long> A, S;
double cache[MAX_N][MAX_N];
double cache2[MAX_N][MAX_N];
double cache3[MAX_N][MAX_N];
double recur(int l, int r) {
    if(l + 1 == r)
        return 0;
    if(l + 2 == r) {
        double ret = A[l] + A[l+1];
        cache2[l][r] = ret;
        cache3[l][r] = ret;
        return ret;
    }

    auto& ret = cache[l][r];
    if(ret > -0.5) return ret;

    recur(l, r-1);
    recur(l+1, r);

    auto su = S[r] - S[l];
    ret = cache2[l][r-1] + cache3[l+1][r];
    ret = (ret + su * (r - l - 1)) / (r - l - 1);
    cache2[l][r] = cache2[l][r-1] + ret;
    cache3[l][r] = cache3[l+1][r] + ret;
    return ret;
} 

void solve(int TestCase) {
    cin >> n;

    for(auto i = 0; i < MAX_N; ++i)
        for(auto j = 0; j < MAX_N; ++j)
            {
                cache[i][j] = -1.0;
                cache2[i][j] = cache3[i][j] = 0;
            }

    A = vector<long long>(n);
    for(auto& x : A) cin >> x;

    S = vector<long long>(A.size() + 1);
    for(auto i = 1; i < S.size(); ++i)
        S[i] = S[i-1] + A[i-1];
    
    auto ret = recur(0, n);
    cout << fixed;
    cout.precision(15);
    cout << ret << endl;
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

