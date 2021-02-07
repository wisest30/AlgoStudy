//
//  698_Div2_D.cpp
//  Codeforces
//
//  Created by mangoxb on 2021/02/07.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

LL gcd(LL x, LL y){
    x = abs(x);
    y = abs(y);
    if( x < y)
        swap(x, y);
    while(x % y){
        LL g = x % y;
        x = y;
        y = g;
    }
    return y;
}

void nezzarAndBoard(){
    int tc;
    cin >> tc;
    while(tc--){
        LL n, k;
        cin >> n >> k;
        vector<LL> x(n);
        
        for(int i = 0; i< n; i++)
            cin >> x[i];
        sort(x.begin(), x.end());
        LL g = x[1] - x[0];
        for(int i = 1; i< n; i++)
            g = gcd(g, x[i] - x[0]);
        
        if( (k - x[0])% g == 0)
            puts("YES");
        else
            puts("NO");
    }
}

int main(void){
    freopen("input.txt","r",stdin);
    nezzarAndBoard();
    return 0;
}
