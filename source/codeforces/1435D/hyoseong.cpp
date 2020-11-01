#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 1e5 + 1;
int n, A[MAX_N * 2], S[MAX_N], s;
void solve(int TestCase) {
    cin >> n;
    s = 0;
    for(auto i = 0; i < 2 * n; ++i) {
        string op;
        cin >> op;
        if(op == "+")
            S[s++] = i;
        else {
            int x;
            cin >> x;
            A[i] = -x;
            
            if(s == 0) {
                cout << "NO" << endl;
                return;
            }

            A[S[--s]] = x;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto i = 0; i < 2 * n; ++i) {
        if(A[i] > 0)
            pq.push(A[i]);
        else if(pq.empty() || pq.top() != -A[i]) {
            cout << "NO" << endl;
            return;
        }
        else
            pq.pop();
    }

    cout << "YES" << endl;
    for(auto i = 0; i < 2 * n; ++i)
        if(A[i] > 0) cout << A[i] << " ";
    cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
 
