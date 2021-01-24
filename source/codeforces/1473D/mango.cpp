//
//  E102_D.cpp
//  Codeforces
//
//  Created by mango on 2021/01/24.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

void program(){
    int tc, n, m;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        vector<int> instructions(n + 1);
        string s;
        cin >> s;
        for(int i = 1; i <= n; i++){
            if(s[i - 1] == '-')
                instructions[i] = -1;
            else
                instructions[i] = 1;
        }
        vector<int> pre_min(1), pre_max(1), su_min(1), su_max(1), pre_sum(1);
        int x = 0;
        for(int i = 1; i <= n; i++){
            x += instructions[i];
            pre_min.push_back(min(pre_min.back(), x));
            pre_max.push_back(max(pre_max.back(), x));
            pre_sum.push_back(x);
        }
        
        x = 0;
        for(int i = n; i > 0; i--){
            x += instructions[i];
            su_min.push_back(min(su_min.back() + instructions[i], 0));
            su_max.push_back(max(su_max.back() + instructions[i], 0));
        }
//        su_min.push_back(0);
//        su_max.push_back(0);
        reverse(su_min.begin(), su_min.end());
        reverse(su_max.begin(), su_max.end());
        
        for(int i = 0; i < m; i++){
            int left, right;
            cin >> left >> right;
            int x_min = min(pre_min[left - 1], pre_sum[left-1] + su_min[right]);
            int x_max = max(pre_max[left - 1], pre_sum[left-1] + su_max[right]);
            cout << x_max - x_min + 1  << "\n";
        }
    }
    
}

int main(void){
    freopen("input.txt","r",stdin);
    program();
    return 0;
}
