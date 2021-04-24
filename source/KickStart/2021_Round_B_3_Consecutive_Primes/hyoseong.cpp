#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

bool is_prime(long long n) {
    if(n <= 1) return false;
    if(n == 2) return true;

    if(n % 2 == 0) return false;

    for(auto div = 3ll; div * div <= n; div += 2)
        if(n % div == 0)
            return false;

    return true;
}

void solve(int TestCase) {
    long long z;
    cin >> z;

    ll s = sqrt(z) + 10;
    while(s * s > z) s--;

    vector<ll> A;
    for(auto i = s+1;; ++i) {
        if(is_prime(i)) {
            A.push_back(i);
            break;
        }
    }

    for(auto i = s; i >= 0; --i) {
        if(is_prime(i)) A.push_back(i);
        if(A.size() == 3) break;
    }

    ll ret = A[0] * A[1];
    if(ret > z) ret = A[1] * A[2];
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
