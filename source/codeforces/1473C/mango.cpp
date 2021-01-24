//
//  E102_C.cpp
//  Codeforces
//
//  Created by mangoxb on 2021/01/24.
//

#include <iostream>
#include <cstdio>
using namespace std;


void noMoreInversion(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, k;
        cin >> n >> k;
        for(int i = 1; i < k - (n - k); i++)
            cout << i << " ";
        for(int i = k; i >= k - (n - k); i--)
            cout << i << " ";
        puts("");
    }
    
}

int main(void){
    freopen("input.txt", "r", stdin);
    noMoreInversion();
    return 0;
}

