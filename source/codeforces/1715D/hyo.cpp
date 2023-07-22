#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, q;
    cin >> n >> q;

    vector<array<int, 3>> Q(q);
    for(auto& x : Q) {
        cin >> x[0] >> x[1] >> x[2];
        x[0]--, x[1]--;
        if(x[0] > x[1]) swap(x[0], x[1]);
    }
    sort(Q.begin(), Q.end(), [&](auto l, auto r) { 
        if(l[1] == r[1]) return l[0] < r[0];
        else return l[1] < r[1];
    });

    vector<int> X(n);
    for(auto& x : Q) {
        X[x[0]] |= ~x[2];
        X[x[1]] |= ~x[2];
    }

    vector<int> ret(n);
    for(auto& x : Q) {
        for(auto i = 0; i < 30; ++i) {
            if(!(x[2] & (1 << i))) continue;
            if(x[0] == x[1] || (X[x[0]] & (1 << i)) || (X[x[1]] & (1 << i))) {
                if(X[x[0]] & (1 << i))
                    ret[x[1]] |= (1 << i);
                else
                    ret[x[0]] |= (1 << i);
            }
        }
    }

    for(auto& x : Q) {
        for(auto i = 0; i < 30; ++i) if(x[2] & (1 << i)) {
            if((ret[x[0]] | ret[x[1]]) & (1 << i)) continue;
            ret[x[1]] |= (1 << i);
        }
    }

    for(auto x : ret) cout << x << " ";
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
