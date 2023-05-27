#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int n;
string ret;

char query1(int i) {
    cout << "? 1 " << (i + 1) << endl;
    char ret;
    cin >> ret;
    return ret;
}

int query2(int l, int r) {
    cout << "? 2 " << (l + 1) << " " << r << endl;
    int ret;
    cin >> ret;
    return ret;
}

void ans() {
    cout << "! " << ret << endl;
}

void solve(int TestCase) {
    cin >> n;
    ret.resize(n);
    
    ret[0] = query1(0);
    for(auto i = 1; i < n; ++i) {
        vector<int> idx;
        string s;

        for(auto j = i - 1; j >= 0; --j) {
            if(s.find(ret[j]) == string::npos) {
                idx.push_back(j);
                s.push_back(ret[j]);
            }
        }

        reverse(idx.begin(), idx.end());
        reverse(s.begin(), s.end());

        auto check = [&](int m) {
            return query2(idx[m], i + 1) != (int)idx.size() - m;
        };

        int l = -1, r = (int)idx.size();
        while(l + 1 < r) {
            int m = (l + r) / 2;
            if(check(m))
                r = m;
            else
                l = m;
        }

        if(l == -1)
            ret[i] = query1(i);
        else
            ret[i] = s[l];
    }

    ans();
}
 
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
