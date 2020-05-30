#include<bits/stdc++.h>
 
using namespace std;
 
void solve(int TestCase) {
    int num, MOD;
    cin >> num >> MOD;
    
    long long ret = 1 % MOD;
    int most_one_pos = 0;
    for(auto i = 31; i >= 0; --i)
    {
        if(num & (1 << i)) {
            most_one_pos = i;
            break;
        }
    }
 
    for(auto i = 0; i <= most_one_pos; ++i)
    {
        long long max_val = (1ll << (i + 1)) - 1;
        if(i == most_one_pos)
            max_val = num;
 
        long long min_val = (1ll << i);
        long long case_cnt = max_val - min_val + 1 + 1;
 
        ret = ret * case_cnt % MOD;
    }
 
    ret = (ret - 1 + MOD) % MOD;
 
    cout << ret << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
