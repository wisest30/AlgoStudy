#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    if(n == -1) {
        exit(0);
    }

    assert(n == 100);

    vector<ll> A;
    for(auto i = 0; i < 30; ++i)
        A.push_back(1ll << i);
    A.push_back(7);
    for(auto i = 1; i < 30; ++i)
        A.push_back((1ll << i) + 1);
    A.push_back(35);
    
    ll cur = 100;
    while(A.size() < n) {
        if(__builtin_popcount(cur) > 3)
            A.push_back(cur);
        ++cur;
    }
    
    for(auto x : A) cout << x << " ";
    cout << endl;

    vector<ll> B(n);
    for(auto& x : B) {
        cin >> x;
        if(x == -1)
            exit(0);
    }
    
    while(A.back() != 35) {
        B.push_back(A.back());
        A.pop_back();
    }

    ll su0 = 0, su1 = 0;
    vector<ll> ret0, ret1;
    for(auto x : B) {
        if(su0 < su1) {
            su0 += x;
            ret0.push_back(x);
        }
        else {
            su1 += x;
            ret1.push_back(x);
        }
    }

    if(su0 > su1) {
        swap(su0, su1);
        swap(ret0, ret1);
    }
    
    ll d = su1 - su0;
    for(auto i = 0; i < 30; ++i) {
        if(d & (1ll << (i + 1))) {
            if(i == 0)
                ret0.push_back(7);
            else
                ret0.push_back((1ll << i) + 1);
            ret0.push_back(1ll << i);
        } else {
            if(i == 0)
                ret0.push_back(7);
            else
                ret0.push_back((1ll << i) + 1);
            ret1.push_back(1ll << i);
        }
    }

    ret1.push_back(35);

    for(auto x : ret0)
        cout << x << " ";
    cout << endl;


/*
    cout << "debug00" << endl;
    ll s = 0;
    for(auto x : ret0) s += x;
    cout << s << endl;
    s = 0;
    for(auto x : ret1) s += x;
    cout << s << endl;*/
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
