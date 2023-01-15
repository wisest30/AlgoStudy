#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    int c = 0;
    for(int i=0; i<k; i++){
        c = max(c, (a[i]+i)/(i+1));
    }
    ans += c;
    for(int i=0; i<k; i++) a[i] -= (i+1) * c;
    if(a[n-1]>0){
        c = (a[n-1] + (k-1))/k;
        ans += c;
        for(int i=0; i<k; i++) a[n-1-i] -= (k-i) * c;
    }
    for(int i=n-2; i>=k; i--){
        if(a[i]>0){
            c = (a[i] + (k-1))/k;
            ans += c;
            for(int j=0; j<k; j++) a[i-j] -= (k-j) * c;
        }
    }
    cout << ans << endl;
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
