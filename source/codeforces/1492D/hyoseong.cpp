#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int a, b, k;
    cin >> a >> b >> k;

    auto x = string(a + b, '0');
    auto y = string(a + b, '0');
    x[0] = y[0] = '1';

    if(b == 1) {
        if(k == 0) cout << "Yes" << "\n" << x << "\n" << y << endl;
        else cout << "No" << endl;
    }
    else if(k > a + b - 2)
        cout << "No" << endl;
    else {
        x[1] = y[1 + k] = '1';

        int remain = b - 2;
        for(auto i = 0; i < x.size(); ++i)
            if(remain > 0 && x[i] == '0' && y[i] == '0')
                --remain, x[i] = y[i] = '1';

        if(remain > 0) cout << "No" << endl;
        else cout << "Yes" << "\n" << x << "\n" << y << endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
       // cout << "Case #"<< i << ": ";
        solve(i);
    }
}
