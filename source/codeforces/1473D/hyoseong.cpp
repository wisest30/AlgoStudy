#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int f(int l1, int r1, int l2, int r2) {
    if(r1 < l2 || r2 < l1)
        return r1 - l1 + 1 + r2 - l2 + 1;
    
    return max(r1, r2) - min(l1, l2) + 1;
}

void solve(int TestCase) {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> l_val(n+1), l_max(n+1), l_min(n+1), r_val(n+1), r_max(n+1), r_min(n+1);
    int x = 0;
    for(auto i = 0; i < n; ++i) {
        if(s[i] == '+') x++;
        else x--;

        l_val[i+1] = x;
        l_max[i+1] = max(l_max[i], x);
        l_min[i+1] = min(l_min[i], x);
    }

    x = 0;
    for(auto i = n-1; i >=0; --i) {
        if(s[i] == '+') x--;
        else x++;

        r_val[i] = x;
        r_max[i] = max(r_max[i+1], x);
        r_min[i] = min(r_min[i+1], x);
    }

    for(auto i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--;

        auto d = l_val[l] - r_val[r];
        auto ret = f(l_min[l], l_max[l], r_min[r] + d, r_max[r] + d);        
        cout << ret << endl;
    }
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
