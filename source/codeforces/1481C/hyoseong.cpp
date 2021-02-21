#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, m;
    cin >> n >> m;

    vector<int> A(n), B(n), C(m);
    for(auto& x : A) cin >> x;
    for(auto& x : B) cin >> x;
    for(auto& x : C) cin >> x;

    unordered_map<int, vector<int>> diff, same;
    for(auto i = 0; i < n; ++i)
        A[i] == B[i] ? same[B[i]].push_back(i) : diff[B[i]].push_back(i);
    
    vector<int> ret(m);
    for(auto i = m - 1; i >= 0; --i) {
        if(diff[C[i]].empty()) {
            if(!same[C[i]].empty())
                ret[i] = same[C[i]].back() + 1;
            else if(i == m - 1) {
                cout << "NO" << endl;
                return;
            }
            else
                ret[i] = ret[i+1];
        }
        else {
            ret[i] = diff[C[i]].back() + 1;
            diff[C[i]].pop_back();
        }
    }

    for(auto& p : diff) {
        if(!p.second.empty()) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    for(auto r : ret)
        cout << r << " ";
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
 
