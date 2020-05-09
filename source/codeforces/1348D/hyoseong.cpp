#include<bits/stdc++.h>
 
using namespace std;
 
void solve(int TestCase) {
    long long n;
    cin >> n;
    
    int a_size = -1;
    for(auto i = 1;; ++i)
    {
        if((1ll << (i+1)) - 1 > n) {
            a_size = i;
            break;
        }
    }
 
    auto A = vector<int>(a_size);
    A[0] = 1;
    for(auto i = 1; i < A.size(); ++i)
        A[i] = A[i-1] * 2;
 
    int bacteria_cnt = (1ll << a_size) - 1;
    if(bacteria_cnt < n)
        A.push_back(n - bacteria_cnt);
    
    sort(A.begin(), A.end());
    cout << ((int)A.size() - 1) << endl;
    for(auto i = 1; i < A.size(); ++i)
        cout << (A[i] - A[i-1]) << " ";
    cout << endl;
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
