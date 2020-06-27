#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long LL;

int fast_exp(LL p, LL e){
    LL cur = 1;
    for(int i = 1; i <= e; i <<= 1){
        if( i & e)
            cur *= p;
        p *= p;
        if( cur > 1000000 || p > 1000000)
            return -1;
    }
    return cur;
}

LL fast_exp(LL p, LL e, LL mod){
    LL cur = 1;
    for(int i = 1; i <= e; i <<= 1){
        if( i & e)
            cur *= p;
        p *= p;
        cur %= mod;
        p %= mod;
    }
    return cur;
}

void minDifferneceBetweenSet(){
    int n, p;
    LL mod = 1000000007;
    vector<int> k;
    cin >> n >> p;
    k.resize(n);
    
    for(int i = 0; i < n; i++)
        cin >> k[i];
    
    sort(k.begin(), k.end(), greater<int>());

    if( p == 1 ){
        cout << n%2 << "\n";
        return ;
    }

    LL x = 1, y = k[0];
    int idx = n;
    for(int i = 1; i < n; i++){
        if( x == 0){
            x = 1;
            y = k[i];
        }
        else{
            if( y == k[i])
                x--;
            else{
                int c = fast_exp(p, y - k[i]);
                if( c == -1 || (LL)c * (LL)x >= (LL)n){
                    idx = i;
                    break;
                }
                x = x * c - 1;
                y = k[i];
            }
        }
    }
    
    LL diff = x * fast_exp(p, y, mod) % mod;
    for(int i = idx; i < n; i++){
        diff = (diff - fast_exp(p, k[i], mod) + mod) % mod;
    }

    cout << diff << "\n";

}

void solve(){
    int tc;
    cin >> tc;
    while(tc--){
        minDifferneceBetweenSet();
    }
}

int main(void){
    freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
