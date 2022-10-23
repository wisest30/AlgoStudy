#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;
    vector<ll> A(n);
    for(auto& x : A) cin >>x ;

    vector<ll> ps(n+1), mps(n+1);
    for(auto i = 1; i <= n; ++i) {
        ps[i] = ps[i-1] + A[i-1];
        mps[i] = mps[i-1] + A[i-1] * (n+1-i);
    }

    ll ret = 0;
    vector<int> st;
    st.push_back(n);
    for(auto left = n-1; left >= 0; --left) {
        while(!st.empty() && ps[st.back()] >= ps[left])
            st.pop_back();
        if(A[left] >= 0) {
            ll right = st.empty() ? n : st.back() - 1;
            ret += mps[right] - mps[left] - (ps[right] - ps[left]) * (n - right);
        }
        st.push_back(left);
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
