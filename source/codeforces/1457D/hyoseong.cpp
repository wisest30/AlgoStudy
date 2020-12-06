#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 1e5 + 10;
int n, A[MAX_N];
void solve(int TestCase) {
    cin >> n;
    for(auto i = 0; i < n; ++i) cin >> A[i];

    if(n > 100) {
        cout << 1 << endl;
        return;
    }

    int ret = INT_MAX;
    for(auto left = 0; left < n; ++left) {
        for(auto right = left + 1; right <= n; ++right) {
            int s1 = 0, s2 = 0;
            for(auto i = left; i < right; ++i)
                s2 ^= A[i];

            for(auto i = left+1; i < right; ++i) {
                s1 ^= A[i-1];
                s2 ^= A[i-1];

                if(s1 > s2)
                    ret = min(ret, right - left - 2);
            }
        }
    }

    if(ret == INT_MAX)
        ret = -1;
    
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
