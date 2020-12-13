#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, x;
    cin >> n >> x;
    vector<int> A(n), B;
    for(auto i = 0; i < n; ++i)
        cin >> A[i];
    
    B = A;

    sort(B.begin(), B.end());
    if(A == B) {
        cout << 0 << endl;
        return;
    }

    auto ret = INT_MAX;
    for(auto lx = 0; lx < n; ++lx) {
        auto last_x = A[lx];

        B = vector<int>{};
        B.push_back(x);
        for(auto i = 0; i < n; ++i)
            if(i != lx) B.push_back(A[i]);
        
        sort(B.begin(), B.end());

        int candi = 0;
        int cur_x = x;
        for(auto i = 0; i < n; ++i) {
            if(A[i] == B[i]) continue;
            if(A[i] <= cur_x) {
                candi = INT_MAX;
                break;
            }
            else {
                candi++;
                cur_x = A[i];
            }
        }

        ret = min(ret, candi);
    }

    if(ret == INT_MAX)
        ret = -1;
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
