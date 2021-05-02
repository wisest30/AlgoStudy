#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for(auto& x : A) cin >> x;

    sort(A.begin(), A.end());

    double ret = 0;
    vector<pair<int, int>> Choice;
    if(A.front() != 1) {
        Choice.push_back({A.front() - 1, A.front() - 1});
        ret = max(ret, (double)(A.front() - 1) / k);
    }
    if(A.back() != k) {
        Choice.push_back({A.back() + 1, k - A.back()});
        ret = max(ret, (double)(k - A.back()) / k);
    }
    for(auto i = 0; i < n-1; ++i) {
        if(A[i] == A[i+1] || A[i] + 1 == A[i+1]) continue;
        Choice.push_back({A[i] + 1, (A[i+1] - A[i] - 1 + 1) / 2});
        ret = max(ret, (double)(A[i+1] - A[i] - 1) / k);
    }

    sort(Choice.begin(), Choice.end(), [](auto& l, auto& r) {
        return l.second > r.second;
    });

    if(Choice.size() >= 2)
        ret = max(ret, (double)(Choice[0].second + Choice[1].second) / k);
    
    cout.precision(15);
    cout << fixed;
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
