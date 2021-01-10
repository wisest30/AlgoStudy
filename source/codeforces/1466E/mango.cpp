//
//  GoodBye2020_E.cpp
//  Codeforces
//
//  Created by mangoxb on 2021/01/10.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define mod 1000000007ll
typedef long long LL;


void apolloVersusPan(){
    int tc;
    LL n;
    cin >> tc;
    while(tc--){
        cin >> n;
        vector<LL> x(n), bit_count(61), p(n);
        LL x_sum = 0;
        for(int i = 0; i < n; i++){
            cin >> x[i];
            for(LL j = 1, k = 0; j <= x[i]; j <<= 1, k++){
                if( x[i] & j )
                    bit_count[k]++;
            }
            x_sum = (x_sum + x[i]) % mod;
        }
        
        for(int i = 0; i < n; i++){
            LL count = 0;
            LL t = 1;
            for(LL j = 1, k = 0; j <= x[i]; j<<=1, k++){
                if( x[i] & j ){
                    count += bit_count[k];
                    p[i] = (p[i] + (j % mod * bit_count[k])) % mod;
                }
               
            }
        }
        
        LL ans = 0;
        for(int i = 0; i < n; i++){
            ans += (p[i] * ((x[i] % mod * n + x_sum - p[i] + mod)% mod )) % mod;
            ans %= mod;
        }
        cout << ans << "\n";
    }
    
}

int main(void){
//    freopen("input.txt", "r", stdin);
    apolloVersusPan();
    return 0;
}
