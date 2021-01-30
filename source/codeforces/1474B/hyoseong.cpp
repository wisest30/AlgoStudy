#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

vector<int> F;
bool initialized = false;

bool isF(int i) {
    for(auto j = 2; j * j <= i; ++j)
        if(i % j == 0) return false;
    return true;
}

void init() {
    initialized = true;
    for(auto i = 2; i <= 30000; ++i)
        if(isF(i)) F.push_back(i);
    // size : 3245
}

void solve(int TestCase) {    
    if(!initialized) init();

    int d;
    cin >> d;

    ll p = *lower_bound(F.begin(), F.end(), 1 + d);
    ll q = *lower_bound(F.begin(), F.end(), p + d);

    ll ret = min(p * p * p, p * q);
    cout << ret << endl;
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
