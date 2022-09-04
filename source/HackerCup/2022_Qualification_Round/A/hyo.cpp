#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, k;
    cin >> n >> k;

    string ans = n > 2 * k ? "NO": "YES";
    map<int, int> cnts;
    for(auto i = 0; i < n; ++i) {
        int s;
        cin >> s;

        if(++cnts[s] >= 3)
            ans = "NO";
    }

    cout << ans << endl;
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


