#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 200005;
int n, A[MAX_N];

int solve2() {
    int ret = 0;

    for(auto l = 0; l < n - 2; ++l) {
        ll sum = A[l+1];
        for(auto r = l + 2; r < n; ++r) {
            if(sum > A[l] && (sum ^ A[l]) > A[l]) break;
            if(sum == (A[l] ^ A[r]) && A[l] > A[r])
                ret++;
            sum += A[r];
        }
    }

    return ret;
}

void solve(int TestCase) {
    cin >> n;
    for(auto i = 0; i < n; ++i)
        cin >> A[i];
    
    auto ret = solve2();
    reverse(A, A + n);
    ret += solve2();

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
