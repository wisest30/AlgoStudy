#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for(auto& x : A) cin >> x;

    set<int> s;
    auto left_min = INT_MAX;
    for(auto i = 0; i < n; ++i) {
        if(A[i] < left_min) {
            left_min = A[i];
            s.insert(i);
        }
    }
    
    for(auto i = 0; i < m; ++i) {
        int k, d;
        cin >> k >> d;
        
        --k;
        A[k] -= d;

        vector<int> removes;
        auto p = prev(s.upper_bound(k));
        if(A[k] > A[*p]); // pass
        else if (k != (*p) && A[k] == A[*p]); // pass
        else {
            ++p;
            while(p != s.end()) {
                if(A[k] <= A[*p]) {
                    removes.push_back(*p);
                    ++p;
                }
                else
                    break;
            }

            s.insert(k);
            for(auto r : removes)
                s.erase(r);
        }
        
        cout << s.size() << " ";
    }
    
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
