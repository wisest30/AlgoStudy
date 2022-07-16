#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> A(m), B(m);
    for(auto i = 0; i < m; ++i) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }
    
    vector<vector<int>> g(n);
    for(auto i = 0; i < m; ++i)
        g[B[i]].push_back(A[i]);
    
    int ret = 0;
    for(auto i = 0; i < n; ++i) {
        set<int> visited;
        vector<int> st;
        st.push_back(i);
        visited.insert(i);
        while(!st.empty()) {
            int cur = st.back();
            st.pop_back();

            if(visited.size() > k)
                break;
            for(auto nxt : g[cur]) {
                if(visited.count(nxt)) continue;
                visited.insert(nxt);
                if(visited.size() > k) break;
                st.push_back(nxt);
            }
        }

        if(visited.size() > k)
            ++ret;
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
