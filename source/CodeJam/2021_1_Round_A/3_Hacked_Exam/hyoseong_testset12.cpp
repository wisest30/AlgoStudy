#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, q;
    cin >> n >> q;

    vector<pair<string, int>> A(n);
    for(auto& x : A) cin >> x.first >> x.second;

    for(auto i = 0; i < A.size(); ++i) {
        if(q - A[i].second > A[i].second) {
            for(auto j = 0; j < A[i].first.size(); ++j)
                A[i].first[j] = A[i].first[j] == 'T' ? 'F' : 'T';
            A[i].second = q - A[i].second;
        }
    }

    sort(A.begin(), A.end(), [](auto& l, auto& r) {
        return l.second < r.second;
    });

    cout << A.back().first << " " << A.back().second << "/1" << endl;
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
