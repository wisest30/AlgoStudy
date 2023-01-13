#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int quest(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}

void ans(int x) {
    cout << "! " << x << endl;
}

void solve(int TestCase) {
    int r = 0;
    for(auto i = 1; i <= 30; ++i) {
        auto a = (1 << (i-1)) - r;
        auto x = quest(a, a + (1 << i));
        if(x == 1 << i)
            r |= 1 << (i-1);
    }

    ans(r);
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
