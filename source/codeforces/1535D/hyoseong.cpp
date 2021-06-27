#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int k;
string s;
vector<int> T;

bool isSub(int p, int c) {
    if(p == c) return true;
    while(c) {
        c--;
        c /= 2;
        if(p == c) return true;
    }

    return false;
}

void calcul(int i) {
    auto l = i * 2 + 1;
    auto r = i * 2 + 2;

    if(l >= s.size()) {
        if(s[i] == '0' || s[i] == '1')
            T[i] = 1;
        else
            T[i] = 2;
        
        return;
    }

    if(s[i] == '0') T[i] = T[r];
    else if(s[i] == '1') T[i] = T[l];
    else T[i] = T[l] + T[r];
}

void upd(int i, int idx, char val) {
    if(!isSub(i, idx))
        return;
    
    if(i == idx)
        s[i] = val;
    else {
        upd(i * 2 + 1, idx, val);
        upd(i * 2 + 2, idx, val);
    }

    calcul(i);
}

void solve(int TestCase) {
    cin >> k;
    cin >> s;
    reverse(s.begin(), s.end());

    T.resize(1 << 20);

    for(auto i = (int)s.size() - 1; i >= 0; --i)
        calcul(i);
    
    int q;
    cin >> q;
    for(auto j = 0; j < q; ++j) {
        int i;
        char val;
        cin >> i >> val;
        
        i = (int)s.size() - i;
        upd(0, i, val);

        cout << T[0] << endl;
    }
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
