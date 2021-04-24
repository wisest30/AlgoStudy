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
    ll z;
    cin >> z;

    ll x = sqrt(z) + 1;
    ll p = -1;
    for(auto i = x + 1;; ++i) {
        if(is_prime(i)) {
            p = i;
            break;
        }
    }

    for(auto i = x; i >= 2; --i) {
        if(is_prime(i)) {
            if(i * p <= z) {
                cout << (i * p) << endl;
                return;
            }

            p = i;
        }
    }
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
