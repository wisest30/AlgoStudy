#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<string> A(n);
    for(auto& x : A) cin >> x;

    int ret = 0;
    for(auto i = 1; i < n; ++i) {
        if(A[i-1].size() < A[i].size()) continue;
        if(A[i-1].size() == A[i].size() && A[i-1] < A[i]) continue;

        auto old = A[i];
        auto size_diff = A[i-1].size() - A[i].size();
        ret += size_diff;
        A[i] += string(size_diff, '0');

        if(A[i-1] < A[i]) continue;

        A[i] = A[i-1];
        for(auto j = (int)A[i].size() - 1; j >= 0; --j) {
            if(A[i][j] != '9') {
                A[i][j]++;
                break;
            }
            else
                A[i][j] = '0';
        }

        if(A[i].find(old) == 0) continue;
        
        ret++;
        A[i] = old + string(size_diff + 1, '0');
    }

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
